struct BIT{

    int ft[maxn];

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

} fen;
