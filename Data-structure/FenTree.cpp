struct BIT{
    int ft[maxn];
    int n;

    void init(int _n){
        n = _n;
    }

    void update(int u, int v){
        while (u <= n) {
            ft[u] += v;
            u += (u & (-u));
        }
    }

    int get(int p){
        int ans = 0;

        while (p > 0) {
            ans += ft[p];
            p -= (p & (-p));
        }
        return ans;
    }

    int get(int l, int r){
        return get(r) - get(l - 1);
    }
} fen;
