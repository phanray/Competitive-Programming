struct SegTree{
    int t[maxn * 2], lz[maxn];

    void build(){
        for (int i = n; i < n + n; ++i)
            t[i] = a[i - n + 1];

        for (int i = n - 1; i > 0; --i)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    void add(int p, int val){
        t[p] += val;

        if (p < n)
            lz[p] += val;
    }

    void lazy(int p){
        for (int j = __lg(p); j > 0; --j){
            int i = p >> j;

            if (lz[i])
                add(i << 1, lz[i]), add(i << 1 | 1, lz[i]), lz[i] = 0;
        }
    }

    void upd(int p){
        while(p > 1)
            p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]) + lz[p];
    }

    void update(int l, int r, int val){
        l += n - 1, r += n;

        int L = l, R = r;

        for (; l < r; l >>= 1, r >>= 1){
            if (l & 1)
                add(l++, val);

            if (r & 1)
                add(--r, val);
        }

        upd(L);
        upd(R - 1);
    }

    int get(int l, int r){
        l += n - 1, r += n;
        int res = 0;

        lazy(l);
        lazy(r - 1);

        for (; l < r; l >>= 1, r >>= 1){
            if (l & 1)
                maximize(res, t[l++]);

            if (r & 1)
                maximize(res, t[--r]);
        }

        return res;
    }
} seg;
