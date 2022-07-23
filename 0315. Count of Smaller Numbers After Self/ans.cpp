
// Gives TLE
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            int c = 0;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > nums[j])
                    c++;
            }
            ans[i] = c;
        }
        return ans;
    }
};

/*Runtime: 991 ms, faster than 39.47% of C++ online submissions for Count of Smaller Numbers After Self.
Memory Usage: 209.3 MB, less than 40.01% of C++ online submissions for Count of Smaller Numbers After Self.*/
class Solution
{
public:
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right)
    {
        vector<pair<int, int>> tmp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right)
        {
            // mind that we're sorting in descending order
            if (v[i].first <= v[j].first)
            {
                tmp[k++] = v[j++];
            }
            else
            {
                // only line responsible to update count, related to problem constraint,
                // remaining part is just regular mergeSort
                count[v[i].second] += right - j + 1;
                tmp[k++] = v[i++];
            }
        }
        while (i <= mid)
        {
            tmp[k++] = v[i++];
        }
        while (j <= right)
        {
            tmp[k++] = v[j++];
        }
        for (int i = left; i <= right; i++)
            v[i] = tmp[i - left];
    }

    void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int left, int right)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid + 1, right);
        merge(count, v, left, mid, right);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int N = nums.size();

        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; i++)
            v[i] = make_pair(nums[i], i);

        vector<int> count(N, 0);
        // sorting in descending order
        mergeSort(count, v, 0, N - 1);

        return count;
    }
};