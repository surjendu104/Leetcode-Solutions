class Solution {
    public int minimumCardPickup(int[] cards) {
        int i = 0, j = 0, n = cards.length;
        int len = Integer.MAX_VALUE;
        HashMap<Integer, Integer> map = new HashMap<>();
        while(j < n) {
            map.put(cards[j], 1 + map.getOrDefault(cards[j], 0));
            while(map.get(cards[j]) >= 2) {
                map.put(cards[i], map.get(cards[i])-1);
                len = Math.min(len, j-i+1);
                i++;
            }
            System.out.println(i+" "+j+" "+len);
            j++;
        }
        return len==Integer.MAX_VALUE?-1:len;
    }
}
/*
[3,4,2,3,4,7]
[95,11,8,65,5,86,30,27,30,73,15,91,30,7,37,26,55,76,60,43,36,85,47,96,6]
*/