class Solution
{
public:
    void primeFactors(int n, set<int> &st)
    {
        int c = 2;
        while (n > 1)
        {
            if (n % c == 0)
            {
                cout << c << " ";
                n /= c;
                st.insert(c);
            }
            else
                c++;
        }
    }
    int distinctPrimeFactors(vector<int> &nums)
    {

        set<int> st;
        for (int i : nums)
        {
            if (i < 2)
                continue;
            else
                primeFactors(i, st);
        }
        return st.size();
    }
};