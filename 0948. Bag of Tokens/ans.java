class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int low = 0, high = tokens.length - 1;
        Arrays.sort(tokens);
        int score = 0;
        int ans = 0;
        while (low <= high) {
            if (power >= tokens[low]) {
                score += 1;
                power -= tokens[low];
                low++;
                ans = Math.max(ans, score);
            } else if (power < tokens[low] && score > 0) {
                score -= 1;
                power += tokens[high];
                high -= 1;
            } else {
                return ans;
            }
        }
        return ans;
    }
}