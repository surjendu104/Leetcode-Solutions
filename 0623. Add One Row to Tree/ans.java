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
//Recursive Solution
class Solution {
    public TreeNode solve(TreeNode node,int val,int depth,int currentDepth) {
        if(node==null)return null;
        if(depth==currentDepth) {
            TreeNode t1 = new TreeNode(val,node.left,null);
            TreeNode t2 = new TreeNode(val,null,node.right);

            node.left = t1;
            node.right = t2;
        }

        node.left = solve(node.left,val,depth,currentDepth+1);
        node.right = solve(node.right,val,depth,currentDepth+1);

        return node;
    }
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth==1)return new TreeNode(val,root,null);
        return solve(root,val,depth,2);
    }
}

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
//Using Stack
class Solution {
    static class Pair {
        TreeNode node;
        int level;
        Pair(TreeNode node,int level) {
            this.node = node;
            this.level = level;
        }
    }
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth==1) {
            TreeNode node = new TreeNode(val,root,null);
            return node;
        }
        Stack<Pair> st = new Stack<Pair>();
        
        st.push(new Pair(root,2));
        while(!st.isEmpty()) {
            Pair temp = st.pop();

            TreeNode node = temp.node;
            int level  =temp.level;

            if(level==depth) {
                TreeNode t1 = new TreeNode(val,node.left,null);
                TreeNode t2 = new TreeNode(val,null,node.right);

                node.left = t1;
                node.right = t2;
            }else {
                if(node.left!=null)st.push(new Pair(node.left,level+1));
                if(node.right!=null)st.push(new Pair(node.right,level+1));
            }
        }
        return root;
    }
}