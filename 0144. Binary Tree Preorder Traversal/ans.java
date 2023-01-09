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
    List<Integer> ans = new ArrayList<>();
    void help(TreeNode root) {
        if(root==null)return;
        ans.add(root.val);
        help(root.left);
        help(root.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        help(root);
        return ans;
    }
}