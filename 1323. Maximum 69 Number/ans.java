class Solution {
    public int maximum69Number (int num) {
        String s = Integer.toString(num);
        char[] ch = s.toCharArray();
        for(int i=0;i<ch.length;i++) {
            if(ch[i]=='6'){
                ch[i]='9';break;
            }
        }
        String a = new String(ch);
        int ans = Integer.parseInt(a);
        return ans;
    }
}


//Another approach
class Solution {
    public int maximum69Number (int num) {
        String s = Integer.toString(num);
        // char[] ch = s.toCharArray();
        String x="";
        int c=0;
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)=='6' && c==0){
                x+='9';c=1;
            }
            else{
                x+=s.charAt(i);
            }
        }
        int ans = Integer.parseInt(x);
        return ans;
    }
}