int w[maxn];
vector<int>a[maxn];

struct Hld{

    int Par[maxn]; // parent
    int Depth[maxn]; // do sau cua node
    int Sz[maxn]; // kich thuoc cua cay con cho cac node
    int Pos[maxn]; // vi tri trong mang cua node
    int Arr[maxn]; // gia tri cua cac phan tu trong mang
    int ChainID[maxn]; // ChainID[i]: Chain ma i nam trong 
    int ChainTop[maxn]; // ChainTop[i]: Node dau tien trong chain i
    int CurChain = 1, CurPos = 1;//dem chuoi,dem vi tri trong mang arr
    int stChain[maxn]; 
    int st[maxn * 4];

    void init(){
        dfs(1, 0);
        hld(1, 0);
        build(1, 1, n);

        for (int i = 1; i <= n; i++)
            stChain[i] = get(1, 1, n, Pos[ChainTop[ChainID[i]]], Pos[i]);
    }

    void dfs(int s, int p){
        Sz[s] = 1;

        for (int u: a[s]) {
            if (u == p) 
                continue;
            
            Par[u] = s;
            Depth[u] = Depth[s] + 1;
            dfs(u, s);
            Sz[s] += Sz[u];
        }
    }

    void hld(int s, int p){
        if (!ChainTop[CurChain])
            ChainTop[CurChain] = s;

        ChainID[s] = CurChain;
        Pos[s] = CurPos;
        Arr[CurPos] = s;
        CurPos++;

        int nxt = 0;
        for (int u: a[s])
            if (u != p)
                if (nxt == 0 || Sz[u] > Sz[nxt])
                    nxt=u;
        
        if (nxt)
            hld(nxt, s);

        for (int u: a[s]) {
            if (u != p && u != nxt){
                CurChain++;
                hld(u, s);
            }
        }
    }

    int Lca(int u, int v){

        while (ChainID[u] != ChainID[v])
            if (ChainID[u] > ChainID[v])
                u = Par[ChainTop[ChainID[u]]];
            else v = Par[ChainTop[ChainID[v]]];

        if (Depth[u] < Depth[v]) 
            return u;
        return v;
    }

    void build(int id, int l, int r){
        if (l == r){
            st[id] = w[Arr[l]];
            return;
        }
        int mid = l + r >> 1;

        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);

        st[id] = st[id << 1] ^ st[id << 1 | 1];
    }

    int get(int id, int l, int r, int u, int v){
        if (l > v || r < u)
            return 0;

        if (l >= u && r <= v)
            return st[id];

        int mid = l + r >> 1;

        return get(id << 1, l, mid, u, v) ^ get(id << 1 | 1, mid + 1, r, u, v);
    }

    int query(int u, int v){
        int lca = Lca(u, v), ans = 0;

        while(ChainID[u] != ChainID[lca]){
            ans ^= stChain[u];

            u = Par[ChainTop[ChainID[u]]];
        }

        while(ChainID[v] != ChainID[lca]) {
            ans ^= stChain[v];
            
            v = Par[ChainTop[ChainID[v]]];
        }

        if(Depth[u] < Depth[v]){
            ans ^= get(1, 1, n, Pos[u], Pos[v]);
        }
        else {
            ans ^= get(1, 1, n, Pos[v], Pos[u]);
        }

        return ans;
    }
} hld;
