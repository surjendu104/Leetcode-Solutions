import java.lang.Character.Subset;
import java.util.ArrayList;

class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> ans = new ArrayList<>();
        int[] per = new int[26];

        for (String s : words2) {
            int[] temp = new int[26];
            for (char c : s.toCharArray()) {
                temp[c - 'a']++;
                per[c - 'a'] = Math.max(per[c - 'a'], temp[c - 'a']);
            }
        }

        boolean f = true;
        for (String s : words1) {
            int[] arr = new int[26];
            for (char c : s.toCharArray()) {
                arr[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (per[i] > arr[i]) {
                    f = false;
                }
            }
            if (f == true)
                ans.add(s);
        }
        return ans;
    }
}

class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> ans = new ArrayList<>();
        int[] per = new int[26];
        int[] temp = new int[26];

        for (String s : words2) {

            for (char c : s.toCharArray()) {
                temp[c - 'a']++;
                per[c - 'a'] = Math.max(per[c - 'a'], temp[c - 'a']);
            }
        }

        boolean f = true;
        for (String s : words1) {
            // int[] arr = new int[26];
            System.arraycopy(per, 0, temp, 0, per.length);
            for (char c : s.toCharArray()) {
                per[c - 'a']--;
            }
            int k = 0;
            while (k < 26) {
                if (per[k++] > 0)
                    break;
            }
            if (k == 26)
                ans.add(s);
        }
        return ans;
    }
}