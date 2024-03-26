class DSU {
    public:
        DSU(int n):
            parent(n)
        {}
        
        void setParent(int x, int p) {
            parent[x] = p;
        }
        int findParent(int x) {
            if(x != parent[x])
                parent[x] = findParent(parent[x]);
            return parent[x];
        }
        bool union_find(int x, int y) {
            int u = findParent(x);
            int v = findParent(y);
            if(u == v) return false;
            parent[u] = v;
            return true;
        }
    private:
        vector<int> parent;
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        if(n == 0) return 0;
        DSU dsu(n);
        
        for(int i = 0; i < n; i+=2) {
            dsu.setParent(row[i], row[i]);
            dsu.setParent(row[i+1], row[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i += 2) {
            if(dsu.union_find(i, i+1)) ans++;
        }
        return ans;
    }
};