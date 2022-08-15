class Solution:
    def romanToInt(self, s: str) -> int:
        translate = {"I": 1, "V": 5, "X": 10,
                     "L": 50, "C": 100, "D": 500, "M": 1000}
        nr = 0
        temp = 0
        for i in range(len(s) - 1, -1, -1):
            integer = translate[s[i]]
            if temp > integer:
                nr -= integer
                temp = integer
            else:
                temp = integer
                nr += temp
        return nr
