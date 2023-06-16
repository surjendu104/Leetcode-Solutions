class Solution {
public:
    const int MOD = 1000000007;
    int numOfWays(vector<int>& nums) {
        return (countBST(nums) - 1 + MOD) % MOD;
    }
    int countBST(vector<int> & nums) {
        if(nums.size() <= 2) {
            return 1;
        }
        vector<int> left, right;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[0])left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        long long leftCount = countBST(left);
        long long rightCount = countBST(right);
        
        long long totalCount = combination(left.size()+right.size(), left.size());
        
        return (leftCount*rightCount%MOD *totalCount%MOD);
    }
    
    int combination(int n, int k) {
        vector<int> c(k+1, 0);
        c[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = min(i, k); j >0; j--) {
                c[j] = (c[j] + c[j-1])%MOD;
            }
        }
        return c[k]%MOD;
    }
};