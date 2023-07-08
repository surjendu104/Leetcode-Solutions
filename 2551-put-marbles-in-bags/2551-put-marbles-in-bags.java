class Solution {
    public long putMarbles(int[] weights, int k) {
        ArrayList<Integer> arr=new ArrayList<>();
        for(int i=0;i<weights.length-1;i++){
            arr.add(weights[i]+weights[i+1]);
        }
        Collections.sort(arr);
        long minimum=0;
        long maximum=0;
        for(int i=0;i<k-1;i++){
            minimum+=arr.get(i);
            maximum+=arr.get(arr.size()-1-i);
        } 
        return maximum-minimum;
    }
}