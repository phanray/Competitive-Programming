struct SegTree{
    int t[maxn * 2];

    void build(){
        for (int i = n; i < n + n; ++i)
            t[i] = a[i - n + 1];

        for (int i = n - 1; i > 0; --i)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    void update(int p, int val){
        for (p += n - 1, t[p] = val, p >>= 1; p > 0; p >>= 1)
            t[p] = max(t[p << 1], t[p << 1 | 1]);
    }

    int get(int l, int r){
        int res = 0;

        for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1){
            if (l & 1)
                maximize(res, t[l++]);

            if (r & 1)
                maximize(res, t[--r]);
        }

        return res;
    }
} seg;
