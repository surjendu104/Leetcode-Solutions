class Solution
{
public:
    int countDigits(int num)
    {
        int ans = 0;
        int t = num;
        while (num != 0)
        {
            int x = num % 10;
            num /= 10;
            if (t % x == 0)
                ans++;
        }
        return ans;
    }
};