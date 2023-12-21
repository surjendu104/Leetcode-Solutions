/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(root == NULL || root == a || root == b) return root;
        TreeNode* left = lowestCommonAncestor(root->left, a, b);
        TreeNode* right = lowestCommonAncestor(root->right, a, b);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root; // if both not null we found the result
    }
};