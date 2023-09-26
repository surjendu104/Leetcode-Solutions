class Solution {
    public String removeDuplicateLetters(String s) {
        int[] lastIndex = new int[26];
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            lastIndex[s.charAt(i)-'a'] = i;
        }
        
        boolean[] vis = new boolean[26];
        Stack<Integer> st = new Stack<>();
        
        for(int i = 0; i < n; ++i) {
            int curr = s.charAt(i) - 'a';
            if(vis[curr]) continue;
            while(!st.isEmpty() && st.peek() > curr && i < lastIndex[st.peek()]){
                vis[st.pop()] = false;
            }
            st.push(curr);
            vis[curr] = true;
        }
        String ans = "";
        while(!st.isEmpty()) {
            char curr = (char)(st.pop()+'a');
            ans = ans + curr;
        }
        return new StringBuilder(ans).reverse().toString();
    }
}