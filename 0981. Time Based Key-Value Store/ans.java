//Using TreeMap
class TimeMap {
    HashMap<String,TreeMap<Integer,String>> mp;
    public TimeMap() {
        mp = new HashMap();
    }
    
    public void set(String key, String value, int timestamp) {
        if(mp.containsKey(key)){
            TreeMap<Integer,String> tm = mp.get(key);
            tm.put(timestamp,value);
            mp.put(key,tm);
        }else{
            TreeMap<Integer,String> tm = new TreeMap<>();
            tm.put(timestamp,value);
            mp.put(key,tm);
        }
    }
    
    public String get(String key, int timestamp) {
        TreeMap<Integer,String> tm = mp.get(key);
        if(tm==null)return "";

        Integer ans = tm.floorKey(timestamp);
        if(ans==null)return "";
        return tm.get(ans);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */


 //Using Binary Search
 class TimeMap {
    
    HashMap<String, Node> map;
    
    public TimeMap() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!map.containsKey(key)) {
            map.put(key, new Node());
        }
        Node node = map.get(key);
        node.values.add(value);
        node.times.add(timestamp);
    }
    
    public String get(String key, int timestamp) {
        Node node = map.get(key);
        if (node == null) {
            return "";
        }
        return binarySearch(node, timestamp);
    }
    
    private String binarySearch(Node node, int timestamp) {
        List<String> values = node.values;
        List<Integer> times = node.times;
        if (timestamp < times.get(0)) {
            return "";
        }
        if (timestamp >= times.get(times.size() - 1)) {
            return values.get(values.size() - 1);
        }
        int left = 0;
        int right = times.size() - 1;
        while (left < right - 1) {
            int mid = (left + right)/2;
            if (times.get(mid) > timestamp) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return values.get(left);
    }
}

class Node {
    List<String> values = new ArrayList<>();
    List<Integer> times = new ArrayList<>();
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */