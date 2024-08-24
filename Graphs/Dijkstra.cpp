int d[maxn];

void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    memset(d, inf, sizeof(d));

    d[s] = 0;
    q.push({0, s});

    while (q.size()){
        int u = q.top().se, dist = q.top().fi; q.pop();

        if (dist > d[u])
            continue;

        for (auto it: a[u]){
            int v = it.fi, w = it.se;

            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                
                q.push({d[v], v});
            }
        }
    }
}
