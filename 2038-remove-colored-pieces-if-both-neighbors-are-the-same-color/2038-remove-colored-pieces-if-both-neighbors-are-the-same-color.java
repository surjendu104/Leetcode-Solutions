class Solution {
    public boolean winnerOfGame(String colors) {
        int n = colors.length();
        int cntA = 0, cntB = 0;
        int tmp1 = 0, tmp2 = 0;
        for(int i = 1; i+1 < n; ++i) {
            char prev = colors.charAt(i-1), next = colors.charAt(i+1);
            char curr = colors.charAt(i);
            if(prev == 'A' && curr == 'A' && next == 'A') tmp1++;
            else {
                cntA += tmp1;
                tmp1 = 0;
            }
            if(prev == 'B' && curr == 'B' && next == 'B'){
                //System.out.println("dbg : " + (i-1) + " " + i + " " + (i+1));
                tmp2++;
            }
            else {
                cntB += tmp2;
                tmp2 = 0;
            }
        }
        cntA += tmp1;
        cntB += tmp2;
        //System.out.println("dbg : " + cntA + " " + cntB);
        if(cntA > cntB) return true;
        else if(cntA < cntB) return false;
        return false;
    }
}