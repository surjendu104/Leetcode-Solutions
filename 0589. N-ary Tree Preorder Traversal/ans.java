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
    List<Integer> help(Node root, List<Integer> ans) {
        if (root == null)
            return ans;

        ans.add(root.val);

        for (int i = 0; i < root.children.size(); i++) {
            ans = help(root.children.get(i), ans);
        }
        return ans;
    }

    public List<Integer> preorder(Node root) {
        List<Integer> res = new ArrayList<>();
        return help(root, res);
    }
}
