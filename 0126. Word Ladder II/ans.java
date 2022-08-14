public class Solution {
    List < List < String >> res;
    Map < Integer, Set > map;
    Set set;
    int goal;
    String es;
    public List < List < String >> findLadders(String beginWord, String endWord, List < String > wordList) {
        res = new LinkedList < > ();
        set = new HashSet < > (wordList);
        es = endWord;
        if (!set.contains(endWord)) return (res);
        int step = 0;
        Queue q = new LinkedList < > ();
        q.offer(beginWord);
        Set seen = new HashSet < > ();
        seen.add(beginWord);
        map = new HashMap < > ();
        boolean found = false;
        while (!q.isEmpty()) {
            int sz = q.size();
            map.put(step, new HashSet < > ());
            while (sz-- > 0) {
                String cs = String.valueOf(q.poll());
                map.get(step).add(cs);
                if (cs.equals(endWord)) {
                    found = true;
                    break;
                }
                Set nbrs = nb(cs, set, seen);
                for (Object ns: nbrs) {
                    q.offer(ns);
                }
            }
            if (found) break;
            step++;
        }
        if (!found) return (res);
        goal = step;
        List list = new LinkedList < > ();
        list.add(es);
        dfs(es, goal, list);
        return (res);
    }

    public void dfs(String s, int level, List < String > list) {
        if (level == 0) {
            List < String > copy = new LinkedList < > (list);
            Collections.reverse(copy);
            res.add(copy);
            return;
        }
        Set < String > nbrs = new HashSet < > ();
        for (Object nss: map.get(level - 1)) {
            if (isnb(String.valueOf(nss), s)) nbrs.add(String.valueOf(nss));
        }
        for (String ns: nbrs) {
            list.add(ns);
            dfs(ns, level - 1, list);
            list.remove(list.size() - 1);
        }
    }
    public boolean isnb(String s1, String s2) {
        int n = s1.length();
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(i)) d++;
        }
        return (d == 1);
    }
    public Set < String > nnb(String s, Set < String > set, int dep) {
        Set < String > res = new HashSet < > ();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int chi = s.charAt(i) - 'a';
            for (int j = 0; j < 26; j++) {
                if (j == chi) continue;
                String ns = s.substring(0, i) + (char)('a' + j) + s.substring(i + 1);
            }
        }
        return (res);
    }
    public Set < String > nb(String s, Set < String > set, Set < String > seen) {
        Set < String > res = new HashSet < > ();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int chi = s.charAt(i) - 'a';
            for (int j = 0; j < 26; j++) {
                if (j == chi) continue;
                String ns = s.substring(0, i) + (char)('a' + j) + s.substring(i + 1);
                if (set.contains(ns) && seen.add(ns)) res.add(ns);

            }
        }
        return (res);
    }
}