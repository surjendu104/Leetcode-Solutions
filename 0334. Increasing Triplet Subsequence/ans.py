class Solution:
    def increasingTriplet(self, nums: list[int]) -> bool:

        first, second = inf, inf

        for third in nums:

            if second < third:
                return True
            if third <= first:
                first = third
            else:
                second = third

        return False
