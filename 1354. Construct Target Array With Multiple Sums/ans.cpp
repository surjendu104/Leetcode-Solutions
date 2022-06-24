

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        priority_queue<int> pq;
        long sum = 0, tmp;
        for (int i = 0; i < target.size(); ++i)
        {
            sum += target[i];
            if (target[i] != 1)
                pq.push(target[i]);
        }
        while (!pq.empty() && pq.top() != 1)
        {
            tmp = pq.top();
            pq.pop();
            sum -= tmp;
            if (sum == 0 || tmp <= sum)
                return 0;
            tmp %= sum;
            sum += tmp;
            if (tmp == 1)
                continue;
            pq.push(tmp ? tmp : sum);
        }
        return 1;
    }
};