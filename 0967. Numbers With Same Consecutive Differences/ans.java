import java.util.ArrayList;
import java.util.List;

class Solution {
    public static void find_num(String s, int n, int idx, int k, List<Integer> ans) {
        if (idx == n) {
            ans.add(Integer.parseInt(s));
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (Math.abs(Character.getNumericValue(s.charAt(s.length() - 1)) - i) == k) {
                find_num(s + Integer.toString(i), n, idx + 1, k, ans);
            }
        }
    }

    public int[] numsSameConsecDiff(int n, int k) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < 10; i++) {
            find_num(Integer.toString(i), n, 1, k, ans);
        }
        int[] res = ans.stream().mapToInt(Integer::intValue).toArray();
        return res;
    }
}