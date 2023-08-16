class Solution {
    public int totalFruit(int[] fruits) {
        int n = fruits.length, i = 0, j = 0;
        int len = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        while(j < n) {
            map.put(fruits[j], map.getOrDefault(fruits[j], 0)+1);
            while(map.size() > 2){
                map.put(fruits[i], map.get(fruits[i])-1);
                if(map.get(fruits[i]) == 0)map.remove(fruits[i]);
                i++;
            }
            
            // System.out.println(i+" "+j);
            len = Math.max(len, j-i+1);
            j++;
        }
        return len;
    }
}