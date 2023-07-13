class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> inDegree(n, 0);
        for(int i = 0; i < n; ++i) {
            for(auto it : adj[i]) {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(!inDegree[i])q.push(i);
        }
        vector<int> linearOrder;
        while(q.size()) {
            int node = q.front();
            q.pop();
            linearOrder.push_back(node);
            for(auto it : adj[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0)q.push(it);
            }
        }
        return linearOrder.size() == numCourses;
    }
};