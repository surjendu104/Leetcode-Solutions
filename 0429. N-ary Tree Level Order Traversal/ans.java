/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;

        Queue<Node> q = new LinkedList();

        q.add(root);

        while (q.isEmpty() != true) {
            List<Integer> v1 = new ArrayList<>();
            List<Node> v2 = new ArrayList<>();

            while (q.isEmpty() != true) {
                v1.add(q.peek().val);
                for (Node i : q.peek().children) {
                    v2.add(i);
                }
                q.poll();
            }
            ans.add(v1);
            for (Node i : v2)
                q.add(i);
        }
        return ans;
    }
}