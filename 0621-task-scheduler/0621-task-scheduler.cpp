class Solution {
public:
    int max(int a, int b){
        if(a>b)return a;
        return b;
    }
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
        }

        int max_count = *max_element(freq.begin(), freq.end());

        int count = (max_count - 1) * (n + 1);

        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == max_count)
            {
                count++;
            }
        }
        count = max(count, tasks.size());

        return count;
    }
};