/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static int ans = 0;
    static void helper(TreeNode root,int low ,int high) {
        if(root.val<=high && root.val>=low)ans+=root.val;
        if(root.left != null)helper(root.left,low,high);
        if(root.right != null)helper(root.right,low,high);
    }
    public int rangeSumBST(TreeNode root, int low, int high) {
        ans = 0;
        helper(root,low,high);
        return ans;
    }
}