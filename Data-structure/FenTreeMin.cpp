struct BITMIN{
    int ft[maxn];
    int n;

    void init(int _n){
        n = _n;
        for (int i = 0; i <= n; ++i)
            ft[i] = i, a[i] = inf;
    }

    int get(int l, int r){
        int m = 0;

        while(l <= r)
            if(r - (r & (-r)) + 1 >= l){
                if(a[m] > a[ft[r]])
                    m = ft[r];

                r -= r & (-r);
            } else {
                if(a[m] > a[r])
                    m = r;

                --r;
            }
        return m;
    }

    void update(int u, int val){
        a[u] = val;

        for (int v = u; u <= n; u += u & (-u))
            if (ft[u] == v){
                int tmp = get(u - (u & (-u)) + 1, u - 1);

                ft[u] = a[tmp] < a[u] ? tmp : u;
            }else if (a[ft[u]] > a[v])
                ft[u] = v;
    }
} fen;
