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

/*
Runtime: 372 ms, faster than 54.50% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 144.7 MB, less than 43.92% of C++ online submissions for Minimum Depth of Binary Tree.
*/
class Solution
{
public:
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return INT_MAX;
        if (root->left == NULL and root->right == NULL)
            return 1;

        int l = dfs(root->left);
        int r = dfs(root->right);
        return 1 + min(l, r);
    }
    int minDepth(TreeNode *root)
    {
        int ans = dfs(root);
        return ans == INT_MAX ? 0 : ans;
    }
};

/*
Runtime: 182 ms, faster than 99.92% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 97.7 MB, less than 99.80% of C++ online submissions for Minimum Depth of Binary Tree.
*/
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = minDepth(root->left);
        int r = minDepth(root->right);

        if (root->left == NULL or root->right == NULL)
            return (root->left == NULL) ? r + 1 : l + 1;

        root->left = NULL;
        root->riight = NULL;

        return min(l, r) + 1;
    }
};
