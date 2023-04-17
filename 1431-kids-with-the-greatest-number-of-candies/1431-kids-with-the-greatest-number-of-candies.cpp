class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(),candies.end());
        vector<bool>ans;
        for(int i:candies) {
            if(i+extraCandies>=maxi)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};