import java.util.HashMap;

class Solution {
    public int minimumRounds(int[] tasks) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : tasks) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        int ans = 0;

        for (int i : map.values()) {
            if (i == 1)
                return -1;
            else if (i % 3 == 0)
                ans += (i / 3);
            else
                ans = ans + (i / 3) + 1;
        }
        return ans;
    }
}