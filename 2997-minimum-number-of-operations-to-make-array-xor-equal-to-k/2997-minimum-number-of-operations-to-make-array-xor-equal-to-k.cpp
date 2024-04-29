class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<20> sum = k;
        for(int ele : nums) sum ^= ele;
        return sum.count();
    }
};