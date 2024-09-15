struct Centroid{
    int child[maxn];
    bool del[maxn];

    int findCentroid(int u, int par, int n) {
        for (int x: e[u])
            if (!del[x] && x != par && child[x] > n / 2)
                return findCentroid(x, u, n); 

        return u;
    }

    void countChild(int u, int par) {
        child[u] = 1;

        for (int x: e[u])
            if (!del[x] && x != par) {

                countChild(x, u);
                child[u] += child[x];
            } 
    }

    void dfs(int u, int par) {

        for (int x: e[u])
            if (!del[x] && x != par)
                dfs(x, u);
    }

    void solve(int u) {
        countChild(u, -1);
        int n = child[u];
        int root = findCentroid(u, -1, n);

        for (int x: e[root])
            if (!del[x]) 
                dfs(x, root);

        del[root] = 1;
        for (int x: e[root])
            if (!del[x]) 
                solve(x);
    }

} centroid;
