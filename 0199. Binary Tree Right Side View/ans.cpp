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

/*Runtime: 7 ms
Memory Usage: 11.9 MB*/
class Solution
{
    vector<int> v;

public:
    void solve(TreeNode *root, int l)
    {
        if (root == NULL)
            return;

        if (l == v.size())
            v.push_back(root->val);
        solve(root->right, l + 1);
        solve(root->left, l + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        solve(root, 0);
        return v;
    }
};