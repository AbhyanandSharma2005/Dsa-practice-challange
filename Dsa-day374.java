class Solution {
    int[] pre;
    int[] suf;
    int[] max;
    char[] A;

    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        int n = s.length();
        pre = new int[4 * n];
        suf = new int[4 * n];
        max = new int[4 * n];
        A = s.toCharArray();

        build(1, 0, n - 1);

        int k = queryIndices.length;
        int[] ans = new int[k];

        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            A[idx] = queryCharacters.charAt(i);
            update(1, 0, n - 1, idx);
            ans[i] = max[1];
        }

        return ans;
    }

    private void build(int node, int start, int end) {
        if (start == end) {
            pre[node] = 1;
            suf[node] = 1;
            max[node] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        merge(node, start, mid, end);
    }

    private void update(int node, int start, int end, int idx) {
        if (start == end) {
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, end, idx);
        }
        merge(node, start, mid, end);
    }

    private void merge(int node, int start, int mid, int end) {
        int left = 2 * node;
        int right = 2 * node + 1;
        int leftSize = mid - start + 1;
        int rightSize = end - mid;

        pre[node] = pre[left];
        suf[node] = suf[right];
        max[node] = Math.max(max[left], max[right]);

        if (A[mid] == A[mid + 1]) {
            if (pre[left] == leftSize) {
                pre[node] += pre[right];
            }
            if (suf[right] == rightSize) {
                suf[node] += suf[left];
            }
            max[node] = Math.max(max[node], suf[left] + pre[right]);
        }
    }
}