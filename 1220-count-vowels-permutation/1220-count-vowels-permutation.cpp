class Solution {
public:
    int countVowelPermutation(int n) {
        unsigned long long val = 0;
        unsigned long long v = ((pow(10,9)+7));
        if(n==1)
            return 5;
        vector<unsigned long long> dpa(n+1);
        vector<unsigned long long> dpe(n+1);
        vector<unsigned long long> dpi(n+1);
        vector<unsigned long long> dpo(n+1);
        vector<unsigned long long> dpu(n+1);
        
        dpa[2] = 1;
        dpe[2] = 2;
        dpi[2] = 4;
        dpo[2] = 2;
        dpu[2] = 1;
        for(int i=3;i<=n;i++)
        {
            dpa[i] = dpe[i-1] % v; // 2
            dpe[i] = dpa[i-1] + dpi[i-1] % v; //5
            dpi[i] = dpa[i-1] + dpe[i-1] + dpo[i-1] + dpu[i-1] % v; //6
            dpo[i] = dpi[i-1] + dpu[i-1] % v; //5
            dpu[i] = dpa[i-1] % v; //1
        }
        val = (dpa[n] + dpe[n] + dpi[n] + dpo[n] + dpu[n]) % v;
        return int(val);
    }
};