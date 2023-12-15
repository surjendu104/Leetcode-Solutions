class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        set<string> st;
        for(auto city : paths) st.insert(city[0]);
        
        for(auto city : paths) {
            if(!st.count(city[1])) 
                return city[1];
        }
        return "";
    }
};