
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

import java.util.Stack;

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null)
            return true;
        if (p == null || q == null)
            return false;

        return (p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right));
    }
}

// Iterative
class Pair {
    TreeNode a;
    TreeNode b;

    Pair(TreeNode a, TreeNode b) {
        this.a = a;
        this.b = b;
    }
}

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Stack<Pair> st;
        Pair x = new Pair(p, q);
        st.add(x);

        while (!st.isEmpty()) {
            Pair n = st.poll();
            if (n.a == null && n.b == null)
                continue;
            if (n.a == null || n.b == null || n.a.val != n.b.val)
                return false;
            st.add(new Pair(n.a.left, n.b.left));
            st.add(new Pair(n.a.right, n.b.right));
        }
        return true;
    }
}