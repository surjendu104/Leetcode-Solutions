class Solution {
    public List<String> commonChars(String[] words) {
        int[] cnt = new int[26];
        Arrays.fill(cnt, Integer.MAX_VALUE);
        
        for(String s : words) {
            int[] cnt1 = new int[26];
            for(Character c : s.toCharArray()) {
                cnt1[c-'a']++;
            }
            for(int i = 0; i < 26; ++i) {
                cnt[i] = Math.min(cnt[i], cnt1[i]);
            }
        }
        
        List<String> ans = new ArrayList<>();
        
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < cnt[i]; ++j) {
                char c = (char)('a'+i);
                ans.add(String.valueOf(c));
            }
        }
        return ans;
    }
}