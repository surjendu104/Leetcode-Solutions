class Solution {
    public String intToRoman(int num) {
        int[] v = new int[]{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] str = new String[]{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        String ans="";
        while(num!=0) {
            for(int i=0;i<v.length;i++) {
                while(num>=v[i]) {
                    num-=v[i];
                    ans+=str[i];
                }
            }
        }
        return ans;
    }
}