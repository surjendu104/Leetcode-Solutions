class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1

        while(l < r):
            if nums[l] == nums[r]:
                r -= 1
            elif nums[l] < nums[r]:
                return nums[l]
            else:
                l -= 1
        return nums[l]


# TLE
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l < r:
            mid = (l+r)//2
            if nums[mid] == nums[r]:
                r -= 1
            elif nums[mid] == nums[l]:
                l -= 1
            elif nums[mid] < nums[r]:
                r = mid
            else:
                l = mid+1
        return nums[l]
