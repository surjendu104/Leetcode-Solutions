//2.monotonic stack
//Time: O(N); Space: O(N)
class Solution {
    public int sumSubarrayMins(int[] arr) {
        final int modulo = 1_000_000_007;

        int[] stack = new int[arr.length + 1];
        int idxStack = 0;

        long res = 0;
        for (int i = 1; i <= arr.length; i++) {
            while (idxStack >= 0 && (i == arr.length || arr[stack[idxStack]] > arr[i])){
                int idx = stack[idxStack--];//pop
                int leftIdx = idxStack < 0 ? -1 : stack[idxStack];
                res += 1l * arr[idx] * (i - idx) * (idx - leftIdx);
            }
            stack[++idxStack] = i;//push
        }
        return (int) (res % modulo);
    }
}