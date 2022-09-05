class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n=s.size();
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        string a="abcdefghijklmnopqrstuvwxyz";
        for(auto i:mp){
            // cout<<i.second[0]<<" "<<i.second[1]<<" "<<distance[a.find(i.first)]<<endl;
            if((i.second[1]-i.second[0]-1)!=distance[a.find(i.first)])return false;
            // cout<<i.first<<" ";
            // for(int x:i.second){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
        }
        return true;
    }
};