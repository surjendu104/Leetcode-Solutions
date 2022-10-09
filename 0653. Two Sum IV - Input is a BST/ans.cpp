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
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root);
        for (int i : ans)
            cout << i << " ";
        unordered_map<int, int> mp;
        for (int i = 0; i < ans.size(); i++)
            mp[ans[i]] = i;
        for (int i = 0; i < ans.size(); i++)
        {
            if (mp.find(k - ans[i]) != mp.end() and mp[k - ans[i]] != i)
            {
                return true;
            }
        }
        return false;
    }
};