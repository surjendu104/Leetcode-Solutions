import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        int[] player = new int[100001];
        int[] loss = new int[100001];
        for (int i = 0; i < matches.length; i++) {
            player[matches[i][0]]++;
            player[matches[i][1]]++;
            loss[matches[i][1]]++;
        }
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        for (int i = 0; i < 100001; i++) {
            if (player[i] != 0 && loss[i] == 0)
                a.add(i);
            if (player[i] != 0 && loss[i] == 1)
                b.add(i);
        }
        ans.add(a);
        ans.add(b);
        return ans;
    }
}