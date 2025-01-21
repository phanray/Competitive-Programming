struct SuffixArray{
    const int maxc = 256;

    int n;
    string s;
    int p[maxn], c[maxn], _p[maxn], _c[maxn], cnt[maxn], lcp[maxn], pos[maxn];
    // int _lcp[maxn][20];

    void init(string _s){
        s = _s + "$";
        n = s.size();

        build_suffix_array();
        build_lcp();
    }

    void build_suffix_array(){
        for (int i = 0; i < n; ++i)
            cnt[s[i]]++;

        for (int i = 1; i < maxc; ++i)
            cnt[i] += cnt[i - 1];

        for (int i = 0; i < n; ++i)
            p[--cnt[s[i]]] = i;

        c[p[0]] = 0;
        int classes = 1;

        for (int i = 1; i < n; ++i)
            c[p[i]] = s[p[i]] == s[p[i - 1]] ? classes - 1 : classes++;

        for (int j = 0; j <= __lg(n - 1); ++j){
            for (int i = 0; i < n; ++i)
                _p[i] = p[i] - (1 << j) < 0 ? p[i] - (1 << j) + n : p[i] - (1 << j);

            fill(cnt, cnt + classes, 0);

            for (int i = 0; i < n; ++i)
                cnt[c[_p[i]]]++;

            for (int i = 1; i < classes; ++i)
                cnt[i] += cnt[i - 1];

            for (int i = n - 1; i >= 0; --i)
                p[--cnt[c[_p[i]]]] = _p[i];

            _c[p[0]] = 0;
            classes = 1;

            for (int i = 1; i < n; ++i)
                _c[p[i]] = make_pair(c[p[i]], c[(p[i] + (1 << j)) % n]) 
                        == make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << j)) % n])
                        ? classes - 1 : classes++;

            swap(c, _c);
        }
    }

    void build_lcp(){
        for (int i = 0; i < n; ++i)
            pos[p[i]] = i;

        for (int i = 0, k = 0; i < n; ++i){
            if (pos[i] == n - 1){
                k = 0;
                continue;
            }

            int j = p[pos[i] + 1];

            while(max(i, j) + k < n && s[i + k] == s[j + k])
                ++k;

            lcp[pos[i]] = k;

            if (k)
                --k;
        }

        // for (int i = 1; i < n; ++i)
        //     _lcp[i][0] = lcp[i];

        // for (int j = 1; j <= __lg(n - 1); ++j)
        //     for (int i = 1; i < n; ++i)
        //         _lcp[i][j] = min(_lcp[i][j - 1], _lcp[i + (1 << (j - 1))][j - 1]);
    }

    // int get(int l, int r){
    //     int k = __lg(r - l);

    //     return min(_lcp[l][k], _lcp[r - (1 << k)][k]);
    // }

    // int Lcp(int l, int r){
    //     if (l == r)
    //         return n - l;

    //     l = pos[l - 1];
    //     r = pos[r - 1];

    //     if (l > r)
    //         swap(l, r);

    //     return get(l, r);
    // }
}suff;
