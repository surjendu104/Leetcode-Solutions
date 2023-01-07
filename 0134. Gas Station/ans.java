class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total_gas=0,total_cost=0;
        int curr_gas=0, starting_point=0;

        for(int i=0;i<gas.length;i++) {
            total_cost += cost[i];
            total_gas += gas[i];
            curr_gas += gas[i]-cost[i];
            
            if(curr_gas<0) {
                starting_point = i+1;
                curr_gas = 0;
            }
        }
        return ((total_gas<total_cost)?-1:starting_point);
    }
}