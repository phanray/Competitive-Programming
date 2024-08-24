struct SparseTable{

    int st[maxn][21];

    void init(){
        for (int i = 1; i <= n; ++i)
            st[i][0] = a[i];

        for (int j = 1; j <=__lg(n); ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int get(int l, int r) {
        int k=__lg(r - l + 1);
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }

}ST;
