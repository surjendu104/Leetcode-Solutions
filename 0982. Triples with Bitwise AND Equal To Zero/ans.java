//TLE
class Solution {
    public int countTriplets(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            for (int j : nums) {
                mp.put(i & j, mp.getOrDefault(i & j, 0) + 1);
            }
        }
        int ans = 0;
        for (int i : nums) {
            for (Map.Entry<Integer, Integer> k : mp.entrySet()) {

                int key = k.getKey(), vlaue = k.getValue();
                if ((i & key) == 0) {
                    ans += vlaue;
                }

            }
        }
        return ans;
    }
}

// Accepted
class Solution {
    public int countTriplets(int[] nums) {
        int[] arr = new int[1 << 16];

        for (int i : nums) {
            for (int j : nums) {
                ++arr[i & j];

            }
        }

        int ans = 0;
        for (int a : nums) {
            for (int i = 0; i < (1 << 16); i++) {
                // System.out.println(arr[i]);
                if ((i & a) == 0) {
                    ans += arr[i];
                }
            }
        }
        return ans;
    }
}