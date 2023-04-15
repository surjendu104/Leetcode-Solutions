class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int[] f = new int[k + 1];
        int sumN = 0;
        for (var pile : piles) {
            int n = pile.size();
            for (int i = 1; i < n; ++i) {
                pile.set(i, pile.get(i) + pile.get(i - 1));
            }

            sumN = Math.min(sumN + n, k); 
            for (int j = sumN; j > 0; --j) {
                for (int w = 0; w < Math.min(n, j); ++w) {
                    f[j] = Math.max(f[j], f[j - w - 1] + pile.get(w)); 
                }
            }
        }

        return f[k];
    }
}