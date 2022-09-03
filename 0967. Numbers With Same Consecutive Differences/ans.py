from typing import List


class Solution:
    def find_num(self, temp: str, n: int, idx: int, k: int, ans: List[int]) -> None:
        if(idx == n):
            ans.extend([int(temp)])
            return
        for i in range(1, 10):
            if abs(int(temp[-1])-i) == k:
                self.find_num(temp+str(i), n, idx+1, k)

    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        ans = List[int]
        for i in range(1, 10):
            self.find_num(str(i), n, 1, k, ans)
        return ans
