struct persistentSegTree {

    int numNode;

    persistentSegTree() {numNode = 1;}

    struct node {
        
        int leftID, rightID, sum;
        node () {leftID = rightID = sum = 0;}
        node(int leftID, int rightID, int sum) : leftID(leftID), rightID(rightID), sum(sum) {};

    } S[20 * maxn];
    
    void build(int id, int l, int r) {

        if (l == r) {

            S[id] = node(0, 0, a[l]);
            return;
        }

        int mid = (l + r) >> 1;
        
        S[id].leftID = ++numNode;
        S[id].rightID = ++numNode;

        build(S[id].leftID, l, mid);
        build(S[id].rightID, mid + 1, r);

        S[id].sum = S[S[id].leftID].sum + S[S[id].rightID].sum;

    }

    int update(int id, int l, int r, int p, int x) {

        if (p < l || p > r)
            return id;

        if (l == r) {

            S[++numNode] = node(0, 0, x);
            return numNode;
        }

        int mid = (l + r) >> 1;

        int idL = update(S[id].leftID, l, mid, p, x);
        int idR = update(S[id].rightID, mid + 1, r, p, x);
        
        numNode++;
        S[numNode].leftID = idL;
        S[numNode].rightID = idR;
        S[numNode].sum = S[idL].sum + S[idR].sum;

        return numNode;

    }

    int get(int id, int l, int r, int u, int v) {

        if (r < u || l > v)
            return 0;
        
        if (l >= u && r <= v)
            return S[id].sum;

        int mid = (l + r) >> 1;
        return get(S[id].leftID, l, mid, u, v) + get(S[id].rightID, mid + 1, r, u, v);

    }

} seg;
