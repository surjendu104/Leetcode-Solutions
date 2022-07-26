
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */

/*
 * Runtime: 12 ms, faster than 36.88% of Java online submissions for Lowest
 * Common Ancestor of a Binary Tree.
 * Memory Usage: 47.6 MB, less than 29.25% of Java online submissions for Lowest
 * Common Ancestor of a Binary Tree.
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q)
            return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left == null)
            return right;
        else if (right == null)
            return left;
        else
            return root;
    }
}