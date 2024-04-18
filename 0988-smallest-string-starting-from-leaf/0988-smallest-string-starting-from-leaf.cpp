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
    void dfs(TreeNode* root, string s, vector<string> &arr) {
        if(!root) return;
        s.push_back('a' + root->val);
        if(!root->left && !root->right) {
            string tmp = s;
            reverse(begin(tmp), end(tmp));
            arr.push_back(tmp);
        } else {
            dfs(root->left, s, arr);
            dfs(root->right, s, arr);
        }
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> arr;
        string s;
        dfs(root, s, arr);
        sort(arr.begin(), arr.end());
        return arr[0];
    }
};