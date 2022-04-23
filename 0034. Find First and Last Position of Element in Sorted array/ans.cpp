class Solution
{
public:
    vector<int> searchRange(vector<int> &N, int T)
    {
        int Tleft = find(T, N);
        if (Tleft == N.size() || N[Tleft] != T)
            return {-1, -1};
        return {Tleft, find(T + 1, N, Tleft) - 1};
    }
    int find(int target, vector<int> arr, int left = 0)
    {
        int right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + right >> 1;
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};