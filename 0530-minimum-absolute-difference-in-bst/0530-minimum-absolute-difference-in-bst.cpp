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
    TreeNode *p;
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return 0;
        getMinimumDifference(root->left);
        if(p != NULL)ans = min(ans, root->val - p->val);
        p = root;
        getMinimumDifference(root->right);
        return ans;
    }
};