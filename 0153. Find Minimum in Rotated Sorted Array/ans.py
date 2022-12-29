from typing import List
class Solution:
    def findMin(self, nums: List[int]) -> int:
        ans = nums[0]
        l, r = 0, len(nums)-1

        while l <= r:
            if nums[l] < nums[r]:
                ans = min(ans, nums[l])
                break
            mid = (l+r)//2
            ans = min(ans, nums[mid])
            if nums[mid] >= nums[l]:
                l = mid+1
            else:
                r = mid-1
        return ans


# 2
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l < r:
            mid = (l+r)//2
            if nums[mid] < nums[r]:
                r = mid
            else:
                l = mid+1
        return nums[l]


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r = 0,len(nums)-1

        while(l<=r):
            mid = l+(r-l)//2
            
            element = nums[mid]
            if element>nums[r]:
                l = mid+1
            elif mid==0 or nums[mid-1]>nums[mid]:
                return nums[mid]
            else:
                r = mid-1
