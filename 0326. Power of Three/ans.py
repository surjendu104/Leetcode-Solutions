import math


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        num = 3**round(math.log10(n)/math.log10(3))
        if num == n:
            return True
        return False

# 2


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        return (3**round(math.log10(n)/math.log10(3)) == n)
