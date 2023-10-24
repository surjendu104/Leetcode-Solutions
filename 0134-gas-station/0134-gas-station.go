func canCompleteCircuit(gas []int, cost []int) int {
    // var n := len(gas)
    var tot_gas = 0
    var tot_cost = 0
    var curr_gas = 0
    var start = 0

    for i, _ := range gas {
        tot_gas += gas[i]
        tot_cost += cost[i]

        curr_gas += (gas[i] - cost[i])
        if(curr_gas < 0) {
            start = i+1
            curr_gas = 0
        }
    }
    if tot_gas < tot_cost {
        return -1 
    }
    return start
}