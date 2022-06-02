
// static int x = []() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(0);
//     return 0;
// }();

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int range = 0;

        for (int i = 0; i < n; i++)
        {

            if (range < i)
                return false;
            range = max(range, i + nums[i]);
        }
        return true;
    }
};