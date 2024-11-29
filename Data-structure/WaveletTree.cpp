struct WaveletTree {
    WaveletTree *L, *R;
    vector<int> pre;
    int l, r;

    WaveletTree(){
        L = R = NULL;
        l = r = 0;
    }

    void build(int posL, int posR, vector<int> &a){
        l = *min_element(a.begin() + posL, a.begin() + posR + 1);
        r = *max_element(a.begin() + posL, a.begin() + posR + 1);

        if (l == r || posL > posR)
            return;

        int mid = l + r >> 1;
        pre.pb(0);

        for (int i = posL; i <= posR; ++i)
            pre.pb(pre.back() + (a[i] <= mid));

        int posMid = stable_partition(a.begin() + posL, a.begin() + posR + 1, [&](int x){
            return x <= mid;
        }) - a.begin() - 1;

        L = new WaveletTree;
        R = new WaveletTree;

        L->build(posL, posMid, a);
        R->build(posMid + 1, posR, a);
    }

    int count(int posL, int posR, int k) {
        if (l > k || r < k || posL > posR)
            return 0;

        if (l == r)
            return posR - posL + 1;

        int cntL = pre[posL - 1];
        int cntR = pre[posR];

        return L->count(cntL + 1, cntR, k) + R->count(posL - cntL, posR - cntR, k);
    }

    int cnt(int posL, int posR, int k) {
        if (r < k || posL > posR)
            return 0;

        if (l >= k)
            return posR - posL + 1;

        int cntL = pre[posL - 1];
        int cntR = pre[posR];

        return L->cnt(cntL + 1, cntR, k) + R->cnt(posL - cntL, posR - cntR, k);
    }

    int Kth(int posL, int posR, int k) {
        if (l == r)
            return l;

        int cntL = pre[posL - 1];
        int cntR = pre[posR];
        int quantity = cntR - cntL;

        if (quantity >= k)
            return L->Kth(cntL + 1, cntR, k);
        else
            return R->Kth(posL - cntL, posR - cntR, k - quantity);
    }
} wave;
