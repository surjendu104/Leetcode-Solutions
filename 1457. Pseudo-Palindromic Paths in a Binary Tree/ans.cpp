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
    int ans = 0;

    void f(TreeNode *root, set<int> st)
    {
        if (st.find(root->val) != st.end())
            st.erase(root->val);
        else
            st.insert(root->val);
        if (!root->left && !root->right)
        {
            if (st.size() <= 1)
                ans++;
            return;
        }
        if (root->left)
            f(root->left, st);
        if (root->right)
            f(root->right, st);
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        if (!root)
            return 0;
        set<int> s;
        f(root, s);
        return ans;
    }
};