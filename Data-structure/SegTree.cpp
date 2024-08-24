struct SegTree{
    int st[maxn * 4];

    void build(int id, int l, int r){
        if (l == r){
            st[id] = a[l];
            return;
        }
        int mid = l + r >> 1;

        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);

        st[id] = min(st[id << 1], st[id << 1 | 1]);
    }

    void update(int id, int l, int r, int i, int val){
        if (l > i || r < i)
            return;

        if (l == r){
            st[id] = val;
            return;
        }
        int mid = l + r >> 1;

        update(id << 1, l, mid, i, val);
        update(id << 1 | 1, mid + 1, r, i, val);

        st[id] = min(st[id << 1], st[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v){
        if (l > v || r < u)
            return inf;

        if (l >= u && r <= v)
            return st[id];

        int mid = l + r >> 1;

        return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
} seg;
