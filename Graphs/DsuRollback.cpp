struct Query{
    int type, u, v;
};

vector<Query>st[maxn * 4];

struct Dsu_Rollback{
    int p[maxn], s[maxn];

    vector<pair<int &, int>>history;

    int snapshot(){
        return history.size();
    }

    void init(int n){
        for (int i = 1; i <= n; i++)
            p[i] = i, s[i] = 1;
    }

    int find(int v){
        return v == p[v] ? v : find(p[v]);
    }

    void uni(int a, int b){
        a = find(a);
        b = find(b);
        
        if (a != b) {
            if (s[a] < s[b]) 
                swap(a,b);

            history.pb({p[b], p[b]});
            history.pb({s[a], s[a]});
            
            p[b] = a;
            s[a] += s[b];
        }
    }

    void rollback(int until){
        while (history.size() > until){
			history.back().fi = history.back().se;
			history.pop_back();
		}
    }

}dsu;

void update(int id, int l, int r, int u, int v, Query q){
    if (l > v || r < u)
        return;

    if (l >= u && r <= v){
        st[id].pb(q);
        return;
    }
    int mid = l + r >> 1;

    update(id << 1, l, mid, u, v, q);
    update(id << 1 | 1, mid + 1, r, u, v, q);
}

void getans(int id, int l, int r){
    int snapshot = dsu.snapshot();

    for (auto q: st[id])
        if (q.type == )
            dsu.uni(q.u, q.v);

    if (l == r){
        for (auto q: st[id])
            if (q.type == )
                cout << ;
    }else{
        int mid = l + r >> 1;

        getans(id << 1, l, mid);
        getans(id << 1 | 1, mid + 1, r);
    }

    dsu.rollback(snapshot);
}
