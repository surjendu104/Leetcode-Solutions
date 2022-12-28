class Solution {
    public int minStoneSum(int[] piles, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a, b) -> b - a);
        for (int i : piles)
            pq.add(i);

        while (k-- != 0) {
            int x = pq.poll();
            pq.add(x - (x / 2));
        }
        int ans = 0;
        while (!pq.isEmpty()) {
            ans += pq.poll();
        }
        return ans;
    }
}