class Solution:
    def mySqrt(self, x: int) -> int:
        low, high = 1, x 
        high = x
        while low <= high:
            mid = (low+high)//2
            if mid == x//mid:
                return mid
            elif m > x//mid:
                high = mid-1
            else:
                low = mid+1    
        return high

class Solution:
    def mySqrt(self, x: int) -> int:
        n = x
        while n*n > x:
            n = (n*n +x)//(2*n)
        return n