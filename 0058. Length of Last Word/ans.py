class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ans = 0
        j = len(s)-1
        while s[j] == ' ':
            j -= 1
        while s[j] != ' ' and j >= 0:
            ans += 1
            j -= 1
            if j < 0:
                break
        return ans


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ans = 0
        for i in reversed(range(len(s))):
            if(s[i] != ' '):
                ans += 1
            else:
                if(ans > 0):
                    return ans
        return ans
