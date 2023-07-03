class Solution {
public:
    bool checkFreqEqualsTwo(string &s){
    unordered_map<char,int>mp;
    for(auto &ch:s){
        mp[ch]++;
    }
    for(auto &it:mp){
        if(it.second>1) return true;
    }
    return false;
}
    bool buddyStrings(string s, string goal) {
     // Base case 
     if(s.size()!=goal.size()) return false ;
     // There might be two cases as given strings s and goal being already equal and not equal 
     if(s==goal){
         return checkFreqEqualsTwo(s);
        }
     else{
         vector<int> index;
         for(int i=0;i<s.size();i++){
             if(s[i]!=goal[i]) index.push_back(i);
         }
         if(index.size()!=2) return false ;
         swap(s[index[0]],s[index[1]]);
         if(s==goal) return true;
        }
        return false;
    }
};