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
    int ans = 0;
    void f(TreeNode* root,int low,int high) {
        if(root->val<=high && root->val>=low)ans+=root->val;
        if(root->left)f(root->left,low,high);
        if(root->right)f(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        f(root,low,high);
        return ans;
    }
};