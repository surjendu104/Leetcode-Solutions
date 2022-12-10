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
    // final double MOD = 1e9+7;
    static long totalSumOfTree = 0, ans = 0;
    /*
    static void getTotalSum(TreeNode root) {
        if(root == null)return;
        totalSumOfTree += root.val;
        getTotalSum(root.left);getTotalSum(root.right);
    }

    static int splitTree(TreeNode root) {
        if(root == null)return 0;
        int sumUnderLeft = splitTree(root.left),sumUnderRight = splitTree(root.right);
        ans = Math.max(ans,(((totalSumOfTree-sumUnderLeft)*sumUnderLeft))-((totalSumOfTree-sumUnderRight)*sumUnderRight));
        return sumUnderLeft+sumUnderRight+root.val;
    }*/

    static long helper(TreeNode root) {
        if(root == null)return 0;
        long sum = helper(root.left) + helper(root.right) + root.val;

        ans = Math.max(ans,sum*(totalSumOfTree-sum));
        return sum;
    }

    public int maxProduct(TreeNode root) {
        totalSumOfTree = 0;
        ans = 0;
        totalSumOfTree = helper(root);
        helper(root);
        return (int)(ans % ((int)Math.pow(10, 9) + 7));
    }
}