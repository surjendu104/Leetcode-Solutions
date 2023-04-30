class Solution {
public:
    vector<int> par, rank ; 
    
    int find(int v){
        if(par[v] == v)
            return v ; 
        return par[v] = find(par[v]) ; 
    }
    
    void unionfn(int a, int b) {
        a = find(a) ; 
        b = find(b) ; 
        if(a!=b) {
            if(rank[a] < rank[b])
                swap(a, b) ; 
            par[b] = a ; 
            if(rank[b] == rank[a])
                rank[a]++ ; 
        }
    }
    
    int calc(int type, vector<vector<int>>& e) {
        int ct = 0 ; 
        for(int i = 0 ; i < e.size() ; i++) {
            if(e[i][0] == type and find(e[i][1]) != find(e[i][2])) {
                ct++ ; 
                unionfn(e[i][1], e[i][2]) ; 
            }
        }
        return ct ; 
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        rank.assign(n+1, 0) ;  
        for(int i =0 ; i <= n ; i++)
            par.push_back(i) ; 
        int common = calc(3, e) ; 
        vector<int> temp = par ; 
        int alice = calc(1, e) ; 
        par = temp ; 
        int bob = calc(2, e) ; 
        if((common + alice != n-1) or (common + bob != n-1))
            return -1 ; 
        return (e.size()-common-alice-bob) ; 
    }
};