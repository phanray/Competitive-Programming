struct Hld{
    int par[maxn], h[maxn], sz[maxn], pos[maxn], arr[maxn], ChainId[maxn], ChainTop[maxn], st[maxn * 4], lz[maxn * 4];
    int Chain = 1, cnt;

    void init(){
        dfs(1, 0);
        hld(1, 0, 1);
        build(1, 1, n);
    }

    void dfs(int u, int p){
        sz[u] = 1;

        for (auto v: e[u]){
            if (v == p) 
                continue;
            
            par[v] = u;
            h[v] = h[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }

    void hld(int u, int p, int top){
        ChainTop[u] = top;
        ChainId[u] = Chain;
        pos[u] = ++cnt;
        arr[cnt] = u;

        int nxt = 0;
        for (auto v: e[u])
            if (v != p)
                if (nxt == 0 || sz[v] > sz[nxt])
                    nxt = v;
        
        if (nxt)
            hld(nxt, u, top);

        for (auto v: e[u]){
            if (v != p && v != nxt){
                ++Chain;
                hld(v, u, v);
            }
        }
    }

    int Lca(int u, int v){
        while (ChainId[u] != ChainId[v])
            if (ChainId[u] > ChainId[v])
                u = par[ChainTop[u]];
            else v = par[ChainTop[v]];

        if (h[u] < h[v]) 
            return u;
        return v;
    }

    void build(int id, int l, int r){
        if (l == r){
            st[id] = w[arr[l]];
            return;
        }
        int mid = l + r >> 1;

        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);

        st[id] = st[id << 1] + st[id << 1 | 1];
    }

    void lazy(int id, int l, int r, int mid){
        if (!lz[id])
            return;

        st[id << 1] += lz[id] * (mid - l + 1);
        st[id << 1 | 1] += lz[id] * (r - mid);

        lz[id << 1] += lz[id];
        lz[id << 1 | 1] += lz[id];

        lz[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val){
        if (l > v || r < u)
            return;

        if (l >= u && r <= v){
            st[id] += val * (r - l + 1);
            lz[id] += val;
            return;
        }
        int mid = l + r >> 1;
        lazy(id, l, r, mid);

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
        lazy(id, l, r, mid);

        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }

    void update(int u, int v, int val){
        while (ChainId[u] != ChainId[v])
            if (ChainId[u] > ChainId[v]){
                update(1, 1, n, pos[ChainTop[u]], pos[u], val);

                u = par[ChainTop[u]];
            }else{
                update(1, 1, n, pos[ChainTop[v]], pos[v], val);

                v = par[ChainTop[v]];
            }
    }

    int query(int u, int v){
        int ans = 0;

        while (ChainId[u] != ChainId[v])
            if (ChainId[u] > ChainId[v]){
                ans += get(1, 1, n, pos[ChainTop[u]], pos[u]);

                u = par[ChainTop[u]];
            }else{
                ans += get(1, 1, n, pos[ChainTop[v]], pos[v]);
                
                v = par[ChainTop[v]];
            }

        if(h[u] < h[v])
            ans += get(1, 1, n, pos[u], pos[v]);
        else 
            ans += get(1, 1, n, pos[v], pos[u]);

        return ans;
    }
} hld;
