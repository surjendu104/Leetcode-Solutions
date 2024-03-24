class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        for(int i : nums) {
            if(st.count(i)) return i;
            else st.insert(i);
        }
        return -1;
    }
};