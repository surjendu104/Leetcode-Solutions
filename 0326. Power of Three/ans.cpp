/* Runtime: 16 ms, faster than 94.46% of C++ online submissions for Power of Three.
Memory Usage: 5.9 MB, less than 29.00% of C++ online submissions for Power of Three. */

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 3 || n == 1)
            return true;
        if (n % 3 != 0 || n == 0)
            return false;
        return isPowerOfThree(n / 3);
    }
};