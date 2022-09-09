class Solution {
    public int numberOfWeakCharacters(int[][] p) {
        Arrays.sort(p, new Comparator<int[]>() {
            public int compare(int a[], int b[]) {
                return ((a[0] == b[0]) ? (b[1] - a[1]) : (a[0] - b[0]));
                // return a[0] - b[0];
            }
        });
        for (int[] i : p) {
            System.out.println(i[0] + "  " + i[1]);
        }
        int ans = 0, mtn = p[p.length - 1][1];

        for (int i = p.length - 2; i >= 0; i--) {
            if (p[i][1] < mtn) {
                ans++;
            }
            mtn = Math.max(mtn, p[i][1]);
        }
        return ans;
    }
}