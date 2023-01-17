class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        cnt1,cnt_flip = 0,0

        for c in s:
            if c=='1':
                cnt+=1
            else:
                cnt_flip+=1
                cnt_flip = min(cnt_flip,cnt1)
        return cnt_flip