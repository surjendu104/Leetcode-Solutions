/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        stack<Node *> st;

        if (root == NULL)
            return ans;
        st.push(root);

        while (st.size())
        {
            Node *node = st.top();
            ans.push_back(node->val);
            st.pop();

            for (int idx = node->children.size() - 1; idx >= 0; idx--)
            {
                Node *child = node->children[idx];
                st.push(child);
            }
        }
        return ans;
    }
};