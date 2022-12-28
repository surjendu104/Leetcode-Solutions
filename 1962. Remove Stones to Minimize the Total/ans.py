class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        q = []
        for i in piles:
            heappush(q, -i)
        while k:
            x = heappop(q)
            heappush(q, x+(-x//2))
            k -= 1
        return -sum(q)
