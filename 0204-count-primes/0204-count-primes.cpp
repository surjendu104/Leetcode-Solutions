class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        int ans=0;
        bool arr[n];
        memset(arr,true, n);
        for(int i=2;i<n;i++)
        {
            if(arr[i])
            {
                ans++;
                for(int j=2*i;j<n;j+=i)
                {
                    arr[j]=false;
                }
            }
        }
        return ans;
    }
};

