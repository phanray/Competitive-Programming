int cnt = 1;

struct Node{
    ll sum;
    Node *left, *right;

    Node(ll val) : sum(val), left(NULL), right(NULL){}
    Node(Node *rs) : sum(rs->sum), left(rs->left), right(rs->right){}
    Node(Node *l, Node *r){
        left = l;
        right = r;
        sum = 0;

        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
} *root[maxn];

struct persistentSeg{
    Node *build(int l, int r){
        if (l == r)
            return new Node(a[l]);

        int mid = l + r >> 1;

        return new Node(build(l, mid), build(mid + 1, r));
    }

    Node *update(Node *node, int l, int r, int v, int val){
        if (l == r)
            return new Node(val);

        int mid = l + r >> 1;

        if (v <= mid)
            return new Node(update(node->left, l, mid, v, val), node->right);
        return new Node(node->left, update(node->right, mid + 1, r, v, val));
    }

    ll get(Node *node, int l, int r, int u, int v){
        if (l > v || r < u)
            return 0;

        if (l >= u && r <= v)
            return node->sum;

        int mid = l + r >> 1;

        return get(node->left, l, mid, u, v) + get(node->right, mid + 1, r, u, v);
    }
} Seg;
