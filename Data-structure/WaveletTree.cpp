struct WaveletTree {

    WaveletTree * childL, * childR;
    vector<int> prefix;
    int l, r;

    WaveletTree () {

        childL = childR = NULL;
        l = r = 0;

    }

    void build(int valL, int valR, int posL, int posR) {

        l = valL;
        r = valR;

        if (l == r || posL > posR)
            return;

        prefix.push_back(0);

        int mid = (l + r) / 2;
        for (int i = posL; i <= posR; i++)
            prefix.push_back(prefix.back() + (a[i] <= mid));
        
        int posMid = stable_partition(a + posL, a + posR + 1, [&](int x) {

            return x <= mid;

        }) - a - 1;

        childL = new WaveletTree;
        childL->build(l, mid, posL, posMid);

        childR = new WaveletTree;
        childR->build(mid + 1, r, posMid + 1, posR);

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

    int cnt(int posL, int posR, int k) {
 
        if (l > k || posL > posR)
            return 0;
 
        if (r <= k)
            return posR - posL + 1;
        
        int cntL = prefix[posL - 1];
        int cntR = prefix[posR];
 
        return childL->cnt(cntL + 1, cntR, k) + childR->cnt(posL - cntL, posR - cntR, k);
 
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

} wave;