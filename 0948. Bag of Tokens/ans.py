class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        l, r = 0, len(tokens)-1
        tokens.sort()
        score, ans = 0, 0

        while l <= r:
            if power >= tokens[l]:
                score += 1
                power -= tokens[l]
                l += 1
                ans = max(ans, score)
            elif power < tokens[l] and score >= 1:
                score -= 1
                power += tokens[r]
                r -= 1
            else:
                return ans
        return ans
