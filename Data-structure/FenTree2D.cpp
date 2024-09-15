struct BIT2D{

    int n, m;
    int ft[maxn][maxn];

    void init(int _n, int _m){
        n = _n;
        m = _m;
    }

    void update(int u, int v, int w){
        
        while (u <= n) {
            int p = v;

            while (p <= m){
                ft[u][p] += w;;

                p += p & (-p);
            }

            u += u & (-u);
        }
    }

    void updRange(int u1, int v1, int u2, int v2, int w){
        update(u1, v1, w);
        update(u1, v2 + 1, -w);
        update(u2 + 1, v1, -w);
        update(u2 + 1, v2 + 1, w);
    }

    int get(int u, int v){
        int ans = 0;

        while (u > 0) {
            int p = v;

            while(p > 0){
                ans += ft[u][p];

                p -= p & (-p);
            }

            u -= u & (-u);
        }
        return ans;
    }

} fen2d;
