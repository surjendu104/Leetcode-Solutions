class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda x: (-x[0], x[1]))

        ans, maxi = 0, 0
        for a, b in properties:
            if b < maxi:
                ans += 1
            maxi = max(maxi, b)
        return ans
