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
// for left child (2*i) + 1 to find index where i == parent index
// for right child (2*i) + 2 to find index where i == parent index
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        ArrayDeque<Pair> queue = new ArrayDeque<>();
        queue.add(new Pair(root, 0));
        int maxWidth = Integer.MIN_VALUE;
        while (!queue.isEmpty()) {
            int size = queue.size();
            int min = queue.getFirst().index;
            int max = queue.getLast().index;
            maxWidth = Math.max(maxWidth, max - min);
            while (size != 0) {
                Pair pair = queue.remove();
                if (pair.node.left != null) {
                    queue.add(new Pair(pair.node.left, (2 * pair.index + 1)));
                }
                if (pair.node.right != null) {
                    queue.add(new Pair(pair.node.right, (2 * pair.index) + 2));
                }
                size--;
            }
        }
        return maxWidth + 1;
    }
}

class Pair {
    TreeNode node;
    int index;
    Pair(TreeNode a, int b) {
        this.node = a;
        this.index = b;
    }
    void setValue(TreeNode a, int b) {
        this.node = a;
        this.index = b;
    }
    Pair getValue() {
        return this;
    }
}