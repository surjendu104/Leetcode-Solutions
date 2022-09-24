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
class Solution
{
public:
    vector<int> ans;
    vector<vector<int>> res;
    void f(TreeNode *root, int tar)
    {
        if (!root)
            return;
        ans.push_back(root->val);
        if (root->left == NULL and root->right == NULL)
        {
            int sum = accumulate(ans.begin(), ans.end(), 0);
            for (int i : ans)
                cout << i << " ";
            cout << endl;
            if (sum == tar)
                res.push_back(ans);
        }
        f(root->left, tar);
        f(root->right, tar);

        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        f(root, targetSum);
        return res;
    }
};