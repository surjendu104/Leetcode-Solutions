class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        HashMap<String, List<String>> m = new HashMap<String, List<String>>();
        for (int i = 0; i < strs.length; i++) {
            char[] ch = strs[i].toCharArray();
            Arrays.sort(ch);
            String temp = new String(ch);
            if (m.containsKey(temp)) {
                m.get(temp).add(strs[i]);
            } else {
                ArrayList<String> l = new ArrayList<>();
                l.add(strs[i]);
                m.put(temp, l);
            }
        }

        for (String i : m.keySet()) {
            ans.add(m.get(i));
        }
        return ans;
    }
}