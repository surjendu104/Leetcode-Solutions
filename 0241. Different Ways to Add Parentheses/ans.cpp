#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] < '0')
            {
                vector<int> v1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> v2 = diffWaysToCompute(expression.substr(i + 1));
                
                for(auto j:v1)for(auto k:v2)switch(expression[i]){
                    case '+':ans.push_back(j+k);break;
                    case '-':ans.push_back(j-k);break;
                    case '*':ans.push_back(j*k);
                }
            }
        }
        if (ans.empty())
            ans.push_back(stoi(expression));
        return ans;
    }
};