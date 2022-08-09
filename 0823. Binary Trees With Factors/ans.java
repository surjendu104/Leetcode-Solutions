import java.util.HashMap;

class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        Arrays.sort(arr);
        HashMap<Integer, Long> mp = new HashMap<>();

        long ans = 1;
        mp.put(arr[0], ans);
        for (int i = 1; i < arr.length; i++) {
            long count = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && mp.containsKey(arr[i] / arr[j])) {
                    count += (mp.get(arr[i] / arr[j]) * mp.get(arr[j]));
                }

            }
            mp.put(arr[i], count);
            ans += count;
        }
        return (int) (ans % 1000000007);
    }
}

class Solution {
    private int mod = (int) 1e9 + 7;
    Set<Integer> st = new HashSet<>();
    Map<Integer, Long> dp = new HashMap<>();

    private long factorCount(int root) {
        if (dp.containsKey(root))
            return dp.get(root);

        // considering root as well into count, so only count = 1
        long count = 1;

        for (int val : st) {
            // check if its divisible or not
            if (root % val != 0)
                continue;

            int factor1 = val, factor2 = root / val;

            // check factors are in set
            if (st.contains(factor2)) {
                // call recursively for its factors
                count += factorCount(val) * factorCount(factor2);
                count %= mod;
            }
        }

        // insert into map
        dp.put(root, count);

        return count;
    }

    public int numFactoredBinaryTrees(int[] arr) {

        // add elements in set
        for (int val : arr)
            st.add(val);

        int res = 0;

        // iterate each element in arr, consider as root
        for (int curVal : arr) {
            res += factorCount(curVal);
            res %= mod;
        }

        return res;
    }
}