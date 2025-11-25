struct Anti_MonopolyTree{
    int lab[maxn], sz[maxn], par[maxn], w[maxn];
    int visited;

    void init(){
        fill(lab + 1, lab + n + 1, 0);
        visited = 0;

        for (int i = 1; i <= n; ++i){
            sz[i] = 1;
            par[i] = 0;
        }
    }

    void add_child(int p, int c){
        par[c] = p;
        sz[p] += sz[c];
    }

    void remove_child(int p, int c){
        par[c] = 0;
        sz[p] -= sz[c];
    }

    void up_tree(int x){
        int y = par[x];
        int z = par[y];

        if (z != 0)
            remove_child(z, y);
        remove_child(y, x);

        if (z != 0 && w[x] > w[y]){
            add_child(z, x);
            add_child(z, y);
        }else{
            add_child(x, y);
            add_child(z, x);
            swap(w[x], w[y]);
        }
    }

    void calibrate(int u){
        while (par[u] != 0)
            if (sz[u] * 3 > sz[par[u]] * 2)
                up_tree(u);
            else
                u = par[u];
    }

    int path_max(int s, int t)
    {
        calibrate(s);
        calibrate(t);
        int a = 0;
        ++visited;
        for (int u = s; u != 0; u = par[u])
            lab[u] = visited;
        for (int v = t; v != 0; v = par[v])
            if (lab[v] == visited)
            {
                a = v; break;
            }
        if (a == 0) return -1;
        int res = 0;
        for (int u = s; u != a; u = par[u])
            maximize(res, w[u]);
        for (int v = t; v != a; v = par[v])
            maximize(res, w[v]);
        return res;
    }

    void add_edge(int u, int v, int weight)
    {
        int temp = path_max(u, v);
        if (temp != -1 && temp <= weight) return;
        while (par[v] != 0) up_tree(v);
        while (par[u] != 0) up_tree(u);
        if (par[v] != u)
            add_child(u, v);
        w[v] = weight;
    }
}am;
