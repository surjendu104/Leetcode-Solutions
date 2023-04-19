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
class Solution{
    public:
    void dfs(TreeNode* root, int& ans, int left, int right) {
        if (!root) return;
        ans = max(ans, max(left, right));
        dfs(root->left, ans, 0, left + 1);
        dfs(root->right, ans, right + 1, 0);
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0, 0);
        return ans;

    }
};