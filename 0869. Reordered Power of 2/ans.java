class Solution {
    public boolean reorderedPowerOf2(int n) {
        String s = String.valueOf(n);
        char temp[] = s.toCharArray();
        Arrays.sort(temp);
        s = new String(temp);
        double num = 2;
        for (double i = 0; i < 30; i++) {
            int x = (int) Math.pow(num, i);
            String str = String.valueOf(x);
            char[] temp2 = str.toCharArray();
            Arrays.sort(temp2);
            str = new String(temp2);
            // sort(str.begin(),str.end());
            System.out.println(s + " " + str);
            if (s.equals(str))
                return true;
        }
        return false;
    }
}