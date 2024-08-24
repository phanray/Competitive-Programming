int tim;
int h[maxn], st[maxn], rmq[maxn][lg];

void dfs(int u, int p){
    st[u] = ++tim;
    rmq[tim][0] = u;

    for (int v: a[u]) {
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
            rmq[++tim][0] = u;
        }
    }
}

void init(){
    for (int j = 1; j <= __lg(tim); j++)
        for (int i = 1; i + (1 << j) - 1 <= tim; i++)
            if (h[rmq[i][j - 1]] < h[rmq[i + (1 << (j - 1))][j - 1]])
                rmq[i][j] = rmq[i][j - 1];
            else rmq[i][j] = rmq[i + (1 << (j - 1))][j - 1];
}

int get(int l, int r){
    if (l > r)
        swap(l, r);
    int k = __lg(r - l + 1);

    if (h[rmq[l][k]] < h[rmq[r - (1 << k) + 1][k]])
        return rmq[l][k];
    
    return rmq[r - (1 << k) + 1][k];
}
