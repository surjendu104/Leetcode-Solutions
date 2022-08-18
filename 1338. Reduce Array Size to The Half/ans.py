class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        n = len(arr)
        freq = [0]*100005
        for i in arr:
            freq[i] = freq[i]+1
        freq.sort(reverse=True)
        ans = 0
        c = 0
        for i in range(0, n):
            if(c < n//2):
                c = c+freq[i]
                ans = ans+1
        return ans
