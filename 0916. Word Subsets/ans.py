from collections import defaultdict


class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        ans = []
        x = defaultdict(lambda: 0)
        words2 = set(words2)
        for w2 in words2:
            d2 = defaultdict(lambda: 0)
            for i in w2:
                d2[i] += 1
                if(x[i] < d2[i]):
                    x[i] = d2[i]

        for w1 in words1:
            d1 = defaultdict(lambda: 0)
            for i in w1:
                d1[i] += 1
            f = True
            for i in x:
                if d1[i] < x[i]:
                    f = False
                    break
            if f:
                ans.append(w1)
        return ans
