/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {

    public int lHeight(TreeNode root) {
        int lh = 0;
        while (root != null) {
            lh++;
            root = root.left;
        }
        return lh;
    }

    public int rHeight(TreeNode root) {
        int rh = 0;
        while (root != null) {
            rh++;
            root = root.right;
        }
        return rh;
    }

    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;

        int leftHeight = lHeight(root);
        int rightHeight = rHeight(root);

        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}

//Alternative 
class Solution {
    public int countNodes(TreeNode root) {
        if(root==null){
            return 0;
        }
        return 1+countNodes(root.left)+countNodes(root.right);
    }
}