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
    map<int, map<int, multiset<int>>> mp;
    void solve(TreeNode *root, int col, int row)
    {
        if (!root)
            return;
        mp[col][row].insert(root->val);
        solve(root->left, col - 1, row + 1);
        solve(root->right, col + 1, row + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        solve(root, 0, 0);
        for (auto m1 : mp)
        {
            vector<int> temp;
            for (auto m2 : m1.second)
            {
                for (auto m3 : m2.second)
                {
                    temp.push_back(m3);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};