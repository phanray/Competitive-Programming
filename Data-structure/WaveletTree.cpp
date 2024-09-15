struct WaveletTree {
    WaveletTree * childL, * childR;
    vector<int> prefix;
    int l, r;

    WaveletTree () {

        childL = childR = NULL;
        l = r = 0;

    }

    void build(int posL, int posR, vector<int> &a) {

        l = *min_element(a.begin() + posL, a.begin() + posR + 1);
        r = *max_element(a.begin() + posL, a.begin() + posR + 1);

        if (l == r || posL > posR)
            return;

        prefix.push_back(0);

        int mid = (l + r) / 2;
        for (int i = posL; i <= posR; i++)
            prefix.push_back(prefix.back() + (a[i] <= mid));
        
        int posMid = stable_partition(a.begin() + posL, a.begin() + posR + 1, [&](int x) {

            return x <= mid;

        }) - a.begin() - 1;

        childL = new WaveletTree;
        childR = new WaveletTree;

        childL->build(posL, posMid, a);
        childR->build(posMid + 1, posR, a);

    }

    int count(int posL, int posR, int k) {

        if (l > k || r < k || posL > posR)
            return 0;

        if (l == r)
            return posR - posL + 1;

        int cntL = prefix[posL - 1];
        int cntR = prefix[posR];

        return childL->count(cntL + 1, cntR, k) + childR->count(posL - cntL, posR - cntR, k);

    }

    int cnt(int posL, int posR, int k) {

        if (r < k || posL > posR)
            return 0;

        if (l >= k)
            return posR - posL + 1;
        
        int cntL = prefix[posL - 1];
        int cntR = prefix[posR];

        return childL->cnt(cntL + 1, cntR, k) + childR->cnt(posL - cntL, posR - cntR, k);

    }

    int Kth(int posL, int posR, int k) {

        if (l == r)
            return l;
        
        int cntL = prefix[posL - 1];
        int cntR = prefix[posR];
        int quantity = cntR - cntL;

        if (quantity >= k)
            return childL->Kth(cntL + 1, cntR, k);
        else
            return childR->Kth(posL - cntL, posR - cntR, k - quantity);

    }
} wave;
