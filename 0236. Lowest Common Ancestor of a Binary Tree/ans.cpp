/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Runtime: 27 ms, faster than 42.15% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 14.4 MB, less than 25.30% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL or root == p or root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else
            return root;
    }
};