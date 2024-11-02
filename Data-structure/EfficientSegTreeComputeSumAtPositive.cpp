struct SegTree{
    int t[maxn * 2];

    void build(){
        for (int i = n; i < n + n; ++i)
            t[i] = a[i - n + 1];
    }

    void update(int l, int r, int val){
        for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1){
            if (l & 1)
                t[l++] += val;

            if (r & 1)
                t[--r] += val;
        }
    }

    int get(int p){
        int res = 0;

        for (p += n - 1; p > 0; p >>= 1) 
            res += t[p];

        return res;
    }
} seg;
