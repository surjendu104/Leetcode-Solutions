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
import java.util.*;
class Solution {
    Map<Integer,Map<Integer,Set<Integer>>> mp =new Map();
    public void solve(TreeNode root,int col,int row){
        if(root==null)return;
        mp.get(col).get(row).add(root.val);
        solve(root.left,col-1,row+1);
        solve(root.right,col+1,row+1);
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>>ans=new ArrayList<>();
        for(Map<Integer,Map<Integer,Set<Integer>>> m1:mp.values()){
            List<Integer>temp=new ArrayList<>();
            for(Map<Integer,Set<Integer>> m2:m1.values()){
                for(Set<Integer> m3:m2.values()){
                    temp.add(m3);
                }
            }
            ans.add(temp);
        }
        return ans;
    }
}