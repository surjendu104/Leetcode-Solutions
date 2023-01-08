import java.util.Map;

class Solution {
    public int maxPoints(int[][] points) {
        int ans = 0;

        for (int[] x : points) {
            Map<Double, Integer> map = new Hashmap<>();
            for (int[] y : points) {
                if (x == y)
                    continue;

                double slope = 0;
                if (x[0] == y[0]) {
                    slope = Double.POSITIVE_INFINITY;
                } else {
                    slope = (double) (y[1] - x[1]) / (double) (y[0] - x[0]);
                }
                map.put(slope, map.getOrDefault(slope, 0) + 1);
                if (map.get(slope) > ans)
                    ans = map.get(slope);
            }
        }
        return ans + 1;
    }
}