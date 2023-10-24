class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int tot_gas = 0, tot_cost = 0;
        int curr_gas = 0, start = 0;;
        
        for(int i = 0; i < n; ++i) {
            tot_gas += gas[i];
            tot_cost += cost[i];
            
            curr_gas += (gas[i] - cost[i]);
            if(curr_gas < 0) {
                start = i+1;
                curr_gas = 0;
            }
        }
        return tot_gas < tot_cost ? -1 : start;
    }
};