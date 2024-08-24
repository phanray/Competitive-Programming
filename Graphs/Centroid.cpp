struct Centroid{

    int maxh, cnt[N], del[N], child[N];

    void countChild(int u, int par) {

        child[u] = 1;
        for (int x : edge[u])
            if (x != par && !del[x]) {

                countChild(x, u);
                child[u] += child[x];
            } 
    }

    int centroid(int u, int par, int n) {

        for (int x :edge[u])
            if (x != par && !del[x] && child[x] > n / 2)
                return centroid(x, u, n); 

        return u;
    }

    void dfs(int u, int par, int type) {

        if (type) {

            //...
        } else {

            //...
        }
    }

    void solve(int u) {

        countChild(u, -1);
        int n = child[u];
        int root = centroid(u, -1, n);

        for (int x :edge[root])
            if (!del[x]) {

                dfs(x, root, 0);
                dfs(x, root, 1);

            }

        del[root] = 1;
        for (int x :edge[root])
            if (!del[x]) solve(x);

    }

} centroid;
