class Solution
{
public:
    int solve(vector<vector<pair<int, int>>> &adj, vector<vector<int>> &dp, int dst, int maxFlight, int src)
    {
        if (dst == src)
            return 0;
        if (maxFlight == 0)
            return INT_MAX;
        if (dp[src][maxFlight] != -1)
            return dp[src][maxFlight];
        int minPrice = INT_MAX;

        for (auto i : adj[src])
        {
            int nextDest = i.first;
            int nextDestFlightPrice = i.second;
            if (nextDestFlightPrice == -1)
                continue;
            i.second = -1;

            int priceToDest = solve(adj, dp, dst, maxFlight - 1, nextDest);
            int totalPrice = (priceToDest != INT_MAX) ? (priceToDest + nextDestFlightPrice) : INT_MAX;
            minPrice = min(minPrice, totalPrice);

            i.second = nextDestFlightPrice;
        }
        return dp[src][maxFlight] = minPrice;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : flights)
            adj[i[0]].push_back({i[1], i[2]});

        k++;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        int ans = solve(adj, dp, dst, k, src);
        return ans != INT_MAX ? ans : -1;
    }
};

// Another approach
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto i : flights)
            adj[i[0]].push_back({i[1], i[2]});

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stop > k)
                continue;

            for (auto i : adj[node])
            {
                int adjNode = i.first;
                int edgeWeight = i.second;
                if (cost + edgeWeight < dist[adjNode] and stop <= k)
                {
                    dist[adjNode] = cost + edgeWeight;
                    q.push({stop + 1, {adjNode, cost + edgeWeight}});
                }
            }
        }

        return dist[dst] != 1e9 ? dist[dst] : -1;
    }
};