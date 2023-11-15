class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        if(arr[0] != 1) arr[0] = 1;
        
        for(int i = 0; i < n-1; ++i) {
            if(arr[i+1] - arr[i] > 1) {
                arr[i+1] = arr[i]+1;
            }
        }
        int maxi = *max_element(begin(arr), end(arr));
        return maxi;
    }
};