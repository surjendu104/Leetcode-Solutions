/*Runtime: 67 ms, faster than 78.13% of C++ online submissions for Search Suggestions System.
Memory Usage: 23.9 MB, less than 91.95% of C++ online submissions for Search Suggestions System.*/

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        int start, bsStart = 0;
        string curr;
        for (char &c : searchWord)
        {
            curr += c;
            start = lower_bound(products.begin() + bsStart, products.end(), curr) - products.begin(); // Get the starting index of word starting with prefix `curr`.
            result.push_back({});
            for (int i = start; i < min(start + 3, (int)products.size()) && !products[i].compare(0, curr.size(), curr); i++) // Add the words with the same prefix to the result.
                result.back().push_back(products[i]);
            bsStart = start; // Reduce the size of elements to binary search on.
        }
        return result;
    }
};