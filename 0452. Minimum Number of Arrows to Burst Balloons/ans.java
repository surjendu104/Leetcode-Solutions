//sort by second element
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

        int ans = 1;
        int lastPosition = points[0][1];
        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > lastPosition) {
                ans++;
                lastPosition = points[i][1];
            }
        }
        return ans;
    }
}

// Sort by first element
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        for (int[] i : points) {
            System.out.println(i[0] + "  " + i[1]);
        }
        int ans = 1;
        int lastPosition = points[0][1];
        for (int i = 0; i < points.length; i++) {
            if (points[i][0] > lastPosition) {
                ans++;
                lastPosition = points[i][1];
            }
            lastPosition = Math.min(lastPosition, points[i][1]);
        }
        return ans;
    }
}
