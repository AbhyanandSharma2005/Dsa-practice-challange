long long n, m;
if (cin >> n >> m) {
    vector<long long> a(m);
    for (long long i = 0; i < m; ++i) {
        cin >> a[i];
    }
    
    sort(a.rbegin(), a.rend());
    
    vector<long long> pq(n, 0);
    make_heap(pq.begin(), pq.end());
    
    for (long long i = 0; i < m; ++i) {
        pop_heap(pq.begin(), pq.end());
        long long current_min = -pq.back();
        pq.pop_back();
        
        pq.push_back(-(current_min + a[i]));
        push_heap(pq.begin(), pq.end());
    }
    
    vector<long long> res(n);
    for (long long i = 0; i < n; ++i) {
        res[i] = -pq[i];
    }
    
    sort(res.begin(), res.end());
    
    for (long long i = 0; i < n; ++i) {
        cout << res[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}