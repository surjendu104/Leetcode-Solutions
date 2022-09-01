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
    public int dfs(TreeNode root,int maxUpto){
        if(root==null)return 0;
        int currMax=root.val;
        int ans=0;
        if(currMax>=maxUpto){
            ans++;
        }
        else{
            currMax=maxUpto;
        }
        return dfs(root.left,currMax)+dfs(root.right,currMax)+ans;
    }
    public int goodNodes(TreeNode root) {
        int maxUpto=root.val;
        return dfs(root.left,maxUpto)+dfs(root.right,maxUpto)+1;
    }
}