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
    int sumNumbers(TreeNode* root) {
        string s;
        return helper(root, s);
    }

    int helper(TreeNode* root, string s) {
        if (!root) return 0;
        s += to_string(root->val);
        if (!root->left && !root->right) {
            return stoi(s);
        }
        int leftSum = helper(root->left, s);
        int rightSum = helper(root->right, s);
        return leftSum + rightSum;
    }
};