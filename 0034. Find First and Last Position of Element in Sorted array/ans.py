""" Runtime: 133 ms, faster than 47.59% of Python3 online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 15.5 MB, less than 50.23% of Python3 online submissions for Find First and Last Position of Element in Sorted Array. """



class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if(nums == []):
            return [-1, -1]

        def left_bound(x):
            l, h = 0, len(nums)
            while(l < h):
                mid = (l+h)//2
                if(nums[mid] < x):
                    l = mid+1
                else:
                    h = mid
            return l

        def right_bound(x):
            l, h = 0, len(nums)
            while(l < h):
                mid = (l+h)//2
                if(nums[mid] <= x):
                    l = mid+1
                else:
                    h = mid
            return l

        lo = left_bound(target)
        if(lo < len(nums) and nums[l] != target) or (lo >= len(nums)):
            return [-1, -1]

        ri = right_bound(target)
        return [lo, ri-1]
