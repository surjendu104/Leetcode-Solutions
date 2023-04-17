class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char,int> mpp1;
        unordered_map<int,int> mpp2;
        for(char c:suits)mpp1[c]++;
        for(auto it:mpp1)if(it.second>=5)return "Flush";
        
        for(int it: ranks)mpp2[it]++;
        bool f1 = false,f2 = false;
        for(auto it:mpp2) {
            if(it.second>=3){
                f1=true;
            }
            else if(it.second>=2)f2 = true;
        }
        if(f1)return "Three of a Kind";
        if(f2)return "Pair";
        return "High Card";
    }
};