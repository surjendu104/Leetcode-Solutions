class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l, r = 0, len(nums)-1

        while l <= r:
            mid = l+(r-l)//2
            if nums[mid] == target:
                return True
            elif nums[mid] < nums[r]:
                if nums[mid] < target and nums[r] >= target:
                    l = mid+1
                else:
                    r = mid-1
            elif nums[mid] > nums[r]:
                if nums[mid] > target and nums[l] <= target:
                    r = mid-1
                else:
                    l = mid+1
            else:
                r -= 1

        return False
