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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> solve = [&](TreeNode* root) -> int {
            if(root == NULL) return 0;
    
            int lsum = max(0, solve(root->left));
            int rsum = max(0, solve(root->right));
            ans = max(ans, lsum+rsum+root->val);
            return  max(lsum, rsum) + root->val ;
        };
        solve(root);
        return ans;
    }
};