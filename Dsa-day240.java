class Fancy {


    private static final long MOD = 1000000007;

    private List<Long> values = new ArrayList<>();
    private List<Long> mul = new ArrayList<>();
    private List<Long> add = new ArrayList<>();

    public Fancy() {
        mul.add(1L);
        add.add(0L);
    }

    public void append(int val) {
        values.add((long) val);
        mul.add(1L);
        add.add(0L);
    }

    public void addAll(int inc) {
        int n = values.size();
        if (n == 0) return;
        add.set(n, (add.get(n) + inc) % MOD);
    }

    public void multAll(int m) {
        int n = values.size();
        if (n == 0) return;
        mul.set(n, (mul.get(n) * m) % MOD);
        add.set(n, (add.get(n) * m) % MOD);
    }

    public int getIndex(int idx) {
        if (idx >= values.size()) return -1;

        long v = values.get(idx);

        for (int i = idx + 1; i < mul.size(); i++) {
            v = (v * mul.get(i) + add.get(i)) % MOD;
        }

        return (int) v;
    }

}

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy obj = new Fancy();
 * obj.append(val);
 * obj.addAll(inc);
 * obj.multAll(m);
 * int param_4 = obj.getIndex(idx);
 */