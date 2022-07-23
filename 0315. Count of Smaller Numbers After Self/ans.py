from typing import List


import bisect
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        arr =[]
        ans = []

        #Traverse the array from right to left
        for i in range(len(nums)-1,-1,-1):
            pos=bisect.bisect_left(arr,nums[i])#get the position of nums[i] in new array arr[]
            
            ans.append(pos)#add the position
            arr.insert(pos,nums[i])#update arr
        return list(reversed(arr))
