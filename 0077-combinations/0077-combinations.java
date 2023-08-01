class Solution {
    // public static List<List<Integer>> ans = new ArrayList<>();
    
    public static void solve(int n, int k, int num, List<Integer> ds, List<List<Integer>> ans) {
        if(n == num+1) {
            if(ds.size() == k) ans.add(new ArrayList<>(ds));
            return;
        }
        
        ds.add(n);
        solve(n+1, k, num, ds, ans);
        ds.remove(ds.size() - 1);
        solve(n+1, k, num, ds, ans);
    }
    public List<List<Integer>> combine(int n, int k) {
        List<Integer> ds = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        solve(1, k, n, ds, ans);
        return ans;
    }
}