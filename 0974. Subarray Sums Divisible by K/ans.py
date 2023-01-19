class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix_sum_mod_k = [0]*k

        prefix_sum = 0
        for i in range(0, len(nums)):
            prefix_sum += nums[i]
            prefix_sum_mod_k[prefix_sum % k] += 1
        ans = prefix_sum_mod_k[0]

        for i in prefix_sum_mod_k:
            if i >= 2:
                ans += i*(i-1)//2
        return ans


# Python always return positive remainder so no check for negative remainder
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix_sum_mod_k = [0]*k

        prefix_sum, ans = 0, 0
        prefix_sum_mod_k[0] = 1
        for i in range(0, len(nums)):
            prefix_sum += nums[i]
            rem = prefix_sum % k
            ans += prefix_sum_mod_k[rem]
            prefix_sum_mod_k[rem] += 1
        return ans
