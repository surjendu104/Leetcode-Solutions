import java.util.*;

class Solution {
    public String convert(String s, int numRows) {
        int n = s.length();
        int i = 0;

        // List<String> ans = new ArrayList<String>(numRows);
        String[] ans = new String[numRows];

        Arrays.fill(ans, "");
        while (i < n) {
            for (int j = 0; j < numRows && i < n; j++) {
                ans[j] += Character.toString(s.charAt(i));
                i++;
            }
            for (int j = numRows - 2; j >= 1 && i < n; j--) {
                ans[j] += Character.toString(s.charAt(i));
                i++;
            }
        }
        String res = "";
        for (String x : ans) {
            res += x;
        }
        return res;
    }
}