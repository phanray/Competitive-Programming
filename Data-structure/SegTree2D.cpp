struct seg2d{
    vector<vector<int>> st;
    vector<int>pos;
    vector<int>idm[maxn];

    void init(int n, int m){
        st.resize(n * 4 + 1, vector<int>(m * 4 + 1));

        prepare(1, 1, m);
        build(1, 1, n);
    }

    void prepare(int id, int l, int r){
        pos.pb(id);
        for (int i = l; i <= r; i++)
            idm[i].pb(id);

        if (l == r)
            return;

        int mid = l + r >> 1;

        prepare(id << 1, l, mid);
        prepare(id << 1 | 1, mid + 1, r);
    }

    void buildm(int id, int l, int r, int idn, int i){
        if (l == r){
            st[idn][id] = a[i][l];

            return;
        }
        int mid = l + r >> 1;

        buildm(id << 1, l, mid, idn, i);
        buildm(id << 1 | 1, mid + 1, r, idn, i);

        st[idn][id] = __gcd(st[idn][id << 1], st[idn][id << 1 | 1]);
    }

    void build(int id, int l, int r){
        if (l == r){
            buildm(1, 1, m, id, l);

            return;
        }
        int mid = l + r >> 1;

        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);

        for (auto x: pos)
            st[id][x] = __gcd(st[id << 1][x], st[id << 1 | 1][x]);
    }

    int getm(int id, int l, int r, int u, int v, int idn){
        if (l > v || r < u)
            return 0;

        if (l >= u && r <= v)
            return st[idn][id];

        int mid = l + r >> 1;

        return __gcd(getm(id << 1, l, mid, u, v, idn), getm(id << 1 | 1, mid + 1, r, u, v, idn));
    }

    int get(int id, int l, int r, int xl, int xr, int yl, int yr){
        if (l > xr || r < xl)
            return 0;

        if (l >= xl && r <= xr)
            return getm(1, 1, m, yl, yr, id);

        int mid = l + r >> 1;

        return __gcd(get(id << 1, l, mid, xl, xr, yl, yr), get(id << 1 | 1, mid + 1, r, xl, xr, yl, yr));
    }

    void updatem(int id, int l, int r, int v, int idn, int val){
        if (l > v || r < v)
            return;

        if (l == r){
            st[idn][id] = val;
            return;
        }

        int mid = l + r >> 1;

        updatem(id << 1, l, mid, v, idn, val);
        updatem(id << 1 | 1, mid + 1, r, v, idn, val);

        st[idn][id] = __gcd(st[idn][id << 1], st[idn][id << 1 | 1]);
    }

    void update(int id, int l, int r, int u, int v, int val){
        if (l > u || r < u)
            return;

        if (l == r){
            updatem(1, 1, m, v, id, val);

            return;
        }
        int mid = l + r >> 1;

        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);

        for (auto x: idm[v])
            st[id][x] = __gcd(st[id << 1][x], st[id << 1 | 1][x]);
    }

}seg;
