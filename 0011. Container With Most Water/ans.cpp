class Solution
{
public:
    int maxArea(vector<int> &a)
    {
        int area = INT_MIN, i = 0, j = a.size() - 1;

        while (i < j)
        {
            area = max(area, min(a[i], a[j]) * (j - i));
            if (a[i] < a[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return area;
    }
};