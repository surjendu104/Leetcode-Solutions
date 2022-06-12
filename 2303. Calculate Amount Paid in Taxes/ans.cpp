#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double res = 0.0;
        int prev = 0;
        for (vector<int> &b : brackets)
        {
            if (income < prev)
                break;
            res += ((min(income, b[0]) - prev) * b[1] * 1.0) / 100;
            prev = b[0];
        }
        return res;
    }
};