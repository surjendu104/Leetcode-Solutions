class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        long int a = abs(dividend), b = abs(divisor);
        long r = 0;
        // if(r==0)return 1;

        long i = 1;

        while (b <= a)
        {
            long int temp = 1, mul = b;
            while (mul <= (a - mul))
            {
                mul += mul;
                temp += temp;
            }
            r += temp;
            a -= mul;
        }
        return (divisor < 0 && dividend >= 0) || (divisor > 0 && dividend < 0) ? ((-1) * r) : r;
    }
};