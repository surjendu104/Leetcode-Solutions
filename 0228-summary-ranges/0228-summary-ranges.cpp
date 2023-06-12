class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> tmp;
//         if(n==1) {
//             tmp.push_back(to_string(nums[0]));
//             return tmp;
//         }
//         if(n==2) {
//             if(nums[0]-nums[1] == -1)tmp.push_back(to_string(nums[0])+"->"+to_string(nums[1]));
//             else {
//                 tmp.push_back(to_string(nums[0]));
//                 tmp.push_back(to_string(nums[1]));
//             }
//             return tmp;
            
//         }
        
        
        
        int i = 0, j = 0;
        
        while(i < n) {
            string s = to_string(nums[i]);
            int j = i;
            for(j = i; j<n-1 && nums[j]+1==nums[j+1]; j++){}
            
            if(i!=j)s+= "->"+to_string(nums[j]);
            // cout<<"dbg : "<<i<<' '<<j<<' '<<s<<endl;
            j++;
            i = j;
            tmp.push_back(s);
            s = "";
        }
        
        // for(string t : tmp)cout<<t<<' ';
        // cout<<endl;
        
        return tmp;
    }
};