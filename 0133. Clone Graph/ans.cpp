class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> v;
        if (node == NULL)
            return node;
        queue<Node *> q;
        q.push(node);
        Node *n1 = new Node(node->val, {});
        v[node] = n1;
        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();

            // Get corresponding cloned node
            Node *new_node = v[n];

            // Cycle through node's list of neighbors and update cloned node's list of neighbors
            for (auto nbr : n->neighbors)
            {
                if (v[nbr])
                {
                    new_node->neighbors.push_back(v[nbr]);
                }
                else
                {
                    Node *new_nbr = new Node(nbr->val, {});
                    q.push(nbr);
                    v[nbr] = new_nbr;
                    new_node->neighbors.push_back(new_nbr);
                }
            }
        }

        return v[node];
    }
};

// Another one

class Solution
{
    unordered_map<int, Node *> um;
    set<int> finished;

public:
    Node *cloneGraph(Node *root)
    {

        if (!root)
            return nullptr;
        return clone(root);
    }

private:
    Node *clone(Node *root)
    {
        int v = root->val;
        if (um.find(v) != um.end())
        {
            return um[v];
        }
        Node *node = new Node(v);
        um[v] = node;
        for (auto &a : root->neighbors)
        {
            node->neighbors.push_back(clone(a));
        }
        return node;
    }
};