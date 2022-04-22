class Solution
{
public:
    int reverse(int x)
    {
        long a = x, y = 0;
        int flag = 0;

        if (x == 0)
            return 0;
        if (x < 0)
        {
            a = (-a);
            flag = 1;
        }
        while (a > 0)
        {
            y = y * 10 + (a % 10);
            a = a / 10;
        }
        if (y < INT_MIN || y > INT_MAX)
            return 0;

        if (!flag)
            return y;
        else
            return (-y);
    }
};