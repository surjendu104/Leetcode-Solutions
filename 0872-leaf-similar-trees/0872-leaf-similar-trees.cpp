/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getLeafNodes(TreeNode* root, vector<int> &a) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) a.push_back(root->val);
        if(root->left)getLeafNodes(root->left, a);
        if(root->right)getLeafNodes(root->right, a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first, second;
        getLeafNodes(root1, first);
        getLeafNodes(root2, second);
        return first == second;
    }
};