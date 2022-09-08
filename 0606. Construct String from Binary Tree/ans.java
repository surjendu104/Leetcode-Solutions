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
    public String ans="";
    
    public void preOrderToString(TreeNode root){
        if(root==null)return;
        ans+=(Integer.toString(root.val));
        if(root.left==null && root.right!=null)ans+=("()");
        if(root.left!=null){
            ans+=("(");
            preOrderToString(root.left);
            ans+=(")");
        }if(root.right!=null){
            ans+=("(");
            preOrderToString(root.right);
            ans+=(")");
        }
    }
    public String tree2str(TreeNode root) {
        preOrderToString(root);
        return ans;
    }
}