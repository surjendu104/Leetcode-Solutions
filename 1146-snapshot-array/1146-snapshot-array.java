class SnapshotArray {
    TreeMap<Integer, Integer>[] Tm;
    int snap_id = 0;
    public SnapshotArray(int length) {
        Tm = new TreeMap[length];
        for (int i = 0; i < length; i++) {
            Tm[i] = new TreeMap<Integer, Integer>();
            Tm[i].put(0, 0);
        }
    }

    public void set(int index, int val) {
        Tm[index].put(snap_id, val);
    }

    public int snap() {
        return snap_id++;
    }

    public int get(int index, int snap_id) {
        return Tm[index].floorEntry(snap_id).getValue();
    }
}