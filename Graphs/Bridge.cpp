int cnt, cau, khop, num[maxn], low[maxn];

void tarjan(int u, int p){
    low[u] = num[u] = ++cnt;
    int node = (p != u);

    for (auto v: a[u])
        if (v != p){
            if (num[v])
                low[u] = min(low[u], num[v]);
            else {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] >= num[v]) cau++;
                if (low[v] >= num[u]) node++;
            }
        }
        
    if (node >= 2) 
        khop++;
}
