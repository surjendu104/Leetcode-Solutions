class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        check, ans, j = 0, 0, 0
        for i in range(len(nums)):
            while (check & nums[i]) != 0:
                check ^= nums[j]
                j += 1
            check |= nums[i]
            ans = max(ans, i-j+1)
        return ans
