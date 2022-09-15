
class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:

        if len(changed) % 2 != 0:
            return []
        frequency_counter = defaultdict(int)
        ans = []
        changed.sort()
        for i in changed:
            if i in frequency_counter:
                frequency_counter[i] += 1
            else:
                frequency_counter[i] = 1

        for i in changed:
            if frequency_counter[i] == 0:
                continue
            if frequency_counter[2*i] == 0:
                return []
            ans.append(i)
            frequency_counter[i] -= 1
            frequency_counter[2*i] -= 1

        return ans
