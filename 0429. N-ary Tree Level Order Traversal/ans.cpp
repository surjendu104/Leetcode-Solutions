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
    vector<vector<int>> levelOrder(Node *root)
    {

        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);

        if (root == NULL)
            return ans;

        while (q.size())
        {
            vector<int> v1;
            vector<Node *> v2;

            while (q.size())
            {
                v1.push_back(q.front()->val);
                for (auto i : q.front()->children)
                    v2.push_back(i);
                q.pop();
            }
            ans.push_back(v1);
            for (auto i : v2)
                q.push(i);
        }
        return ans;
    }
};