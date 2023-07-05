class Solution {
    public boolean isAnagram(String a, String b) {
        if(a.length()!=b.length())return false;
        Map<Character, Integer> map = new HashMap<>();

        for (Character c : a.toCharArray()) {
            if (map.containsKey(c))
                map.put(c, map.get(c) + 1);
            else
                map.put(c, 1);
        }
        for (Character c : b.toCharArray()) {
            if (map.containsKey(c)) {
                if (map.get(c) == 0)
                    return false;
                else
                    map.put(c, map.get(c) - 1);
            } else
                return false;
        }

        return true;
    }
}