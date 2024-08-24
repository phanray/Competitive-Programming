struct SegTree{
    int st[maxn * 4], lz[maxn * 4];

    void build(int id, int l, int r){
        if (l == r){
            st[id] = a[l];
            return;
        }
        int mid = l + r >> 1;

        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);

        st[id] = st[id << 1] + st[id << 1 | 1];
    }

    void lazy(int id){
        if (!lz[id])
            return;

        st[id << 1] += lz[id];
        st[id << 1 | 1] += lz[id];

        lz[id << 1] += lz[id];
        lz[id << 1 | 1] += lz[id];

        lz[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val){
        if (l > v || r < u)
            return;

        if (l >= u && r <= v){
            st[id] += val;
            lz[id] += val;
            return;
        }
        int mid = l + r >> 1;
        lazy(id);

        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);

        st[id] = st[id << 1] + st[id << 1 | 1];
    }

    int get(int id, int l, int r, int u, int v){
        if (l > v || r < u)
            return 0;

        if (l >= u && r <= v)
            return st[id];

        int mid = l + r >> 1;
        lazy(id);

        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
} seg;
