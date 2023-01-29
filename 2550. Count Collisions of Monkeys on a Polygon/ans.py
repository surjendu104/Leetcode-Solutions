class Solution:
    def monkeyMove(self, n):
        mod = 10 ** 9 + 7
        return (pow(2, n, mod) - 2) % mod