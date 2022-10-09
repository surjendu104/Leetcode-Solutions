import java.util.HashSet;

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

    public boolean dfs(TreeNode root, int k, HashSet<Integer> st) {
        if (root == null) {
            return false;
        }
        if (st.contains(k - root.val)) {
            return true;
        }
        st.add(root.val);
        return dfs(root.left, k, st) || dfs(root.right, k, st);
    }

    public boolean findTarget(TreeNode root, int k) {
        HashSet<Integer> st = new HashSet<>();
        return dfs(root, k, st);
    }
}