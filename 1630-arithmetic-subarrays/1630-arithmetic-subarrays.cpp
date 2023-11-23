class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        vector<bool> ans;
        for(int i = 0; i < l.size(); ++i) {
            int a = l[i], b = r[i];
            if(b-a+1 < 2) {
                ans.push_back(false);
                continue;
            }else if(b-a+1 == 2) {
                ans.push_back(true);
                continue;
            }
            vector<int> tmp(nums.begin()+a, nums.begin()+b+1);
            // for(int i : tmp) cout << i << ' ';
            // cout << '\n';
            sort(tmp.begin(), tmp.end());
            int diff = tmp[1] - tmp[0];
            bool f = true;
            for(int i = 1; i < tmp.size() - 1; ++i) {
                if(tmp[i+1] - tmp[i] != diff) {
                    f = false;
                    break;
                }
            }
            if(!f) ans.push_back(false);
            else ans.push_back(true);
        }
        
        return ans;
    }
};