class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> st, temp;
        for(int i : nums) {
            if(st.count(i)) temp.insert(i);
            else st.insert(i);
        }
        vector<int> ans(begin(temp), end(temp));
        return ans;
    }
};