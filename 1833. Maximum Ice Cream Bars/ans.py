class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        ans = 0
        costs.sort()

        for i in costs:
            if coins >= i:
                coins -= i
                ans += 1
            else:
                break
        return ans
