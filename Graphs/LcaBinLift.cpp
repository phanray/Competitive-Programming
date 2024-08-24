int h[maxn],up[maxn][21];

void dfs(int u){
    for (int v: a[u])
        if (v != up[u][0]){
            h[v] = h[u] + 1;
            up[v][0] = u;

            for (int j = 1; j <= __lg(h[v]); j++)
                up[v][j] = up[up[v][j - 1]][j - 1];

            dfs(v);
        }
}

int lca(int u, int v){
    if (h[u] != h[v]){
        if (h[u] < h[v])
            swap(u, v);
        int k = h[u] - h[v];

        for (int j = 0; j <=__lg(k); j++)
            if (k >> j & 1)
                u = up[u][j];
    }
    if (u == v)
        return u;

    int k = __lg(h[u]);
    for (int j = k; j >= 0; j--)
        if (up[u][j] != up[v][j])
            u = up[u][j], v = up[v][j];
        
    return up[u][0];
}
