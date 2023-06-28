class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> probability(n);
        probability[start] = 1.0;
        
        vector<pair<int, double>> g[n];
        for(int i = 0; i < edges.size(); ++i) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        
        while(!pq.empty()) {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            
            if(node == end)
                return prob;
            
            for(auto it : g[node]) {
                int adjNode = it.first;
                double adjProb = it.second;
                
                if(adjProb * prob > probability[adjNode]) {
                    probability[adjNode] = adjProb * prob;
                    pq.push({probability[adjNode], adjNode});
                }
            }
        }
        
        return 0.0;
    }
};
