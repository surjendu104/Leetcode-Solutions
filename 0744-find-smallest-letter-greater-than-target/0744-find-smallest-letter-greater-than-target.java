class Solution {
    public char nextGreatestLetter(char[] a, char target) {
        int l=0;
        int r=a.length-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(target<a[mid]) r=mid-1;
            else l=mid+1;
        }
        return a[l%a.length];
    }
}