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
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> q =new LinkedList<TreeNode>();
        List<Double>ans = new ArrayList<>();
        
        q.add(root);
        while(q.size()!=0){
            Double sum=0.0,avg=0.0;
            Integer n=q.size();
            
            for(int i=0;i<n;i++){
                TreeNode temp=q.peek();
                q.remove();
                sum+=(temp.val);
                
                if(temp.left!=null)q.add(temp.left);
                if(temp.right!=null)q.add(temp.right);
                
            }
            avg=sum/n;
            ans.add(avg);
        }
        return ans;
    }
}