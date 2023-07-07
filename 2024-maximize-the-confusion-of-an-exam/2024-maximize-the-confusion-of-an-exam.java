class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int i = 0;
        int j = 0;

        int countF = 0;
        int countT = 0;
        int ans = 0;
        while(j < answerKey.length()) {
            char ch = answerKey.charAt(j);
            if(ch == 'T') {
                countT++;
            } else {
                countF++;
            }

            // shrink the window, if exceeds the min of countT/countF
            while(Math.min(countT, countF) > k) {
                ch = answerKey.charAt(i);
                if(ch == 'T') {
                    countT--;
                } else {
                    countF--;
                }
                i++;
            }
            ans = Math.max(ans, (j-i+1));
            j++;
        }
        return ans;
    }
}