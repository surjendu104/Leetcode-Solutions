/*Runtime: 9 ms, faster than 38.89% of C++ online submissions for Fibonacci Number.
Memory Usage: 5.9 MB, less than 41.61% of C++ online submissions for Fibonacci Number.*/

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }
};

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
Memory Usage: 6.1 MB, less than 9.61% of C++ online submissions for Fibonacci Number.*/
class Solution
{
public:
    int fib(int n)
    {
        vector<int> a(n + 1);
        a[0] = 0;
        if (!n)
        {
            return a[0];
        }
        a[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }

        return a[n];
    }
};