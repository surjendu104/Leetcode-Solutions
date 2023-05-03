class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        set<int>st1, st2;
        for(int i : nums1)st1.insert(i);
        for(int i : nums2)st2.insert(i);
        
        vector<int> tmp;
        for(int i : st1) {
            if(st2.count(i) == 0)tmp.push_back(i);
        }
        ans.push_back(tmp);
        tmp.clear();
        for(int i : st2) {
            if(st1.count(i) == 0)tmp.push_back(i);
        }
        ans.push_back(tmp);
        return ans;
    }
};