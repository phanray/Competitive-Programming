struct line {
    ll a, b;

    line(): a(0), b(LLONG_MIN) {}
    line (ll a, ll b): a(a), b(b) {}

    ll calc (ll x) {return a * x + b;}
};

const ll M = 1e9;

struct node {
    line tr;
    node *left, *right;

    node(): tr(0, LLONG_MIN), left(NULL), right(NULL) {}

    ll div(ll a, ll b){ 
        return a / b - ((a ^ b) < 0 && a % b);
    }

    void update (line f, ll l = -M, ll r = M){
        if (l == r) {
            tr = f.calc(l) > tr.calc(l) ? f : tr;
            return;
        }

        ll mid = div(l + r, 2);

        if (f.calc(mid) > tr.calc(mid))
            swap(tr, f);

        if (f.a < tr.a){
            if (left == NULL) 
                left = new node();

            left->update(f, l, mid);
        }

        if (f.a > tr.a){
            if (right == NULL) 
                right = new node(); 

            right->update(f, mid + 1, r);
        }
    }

    ll query (ll p, ll l = -M, ll r = M){
        ll res = tr.calc(p);
        ll mid = div(l + r, 2);

        if (l == r) 
            return res;

        if (p <= mid)
            return (left == NULL ? res : max(res, left->query(p, l, mid)));

        return (right == NULL ? res : max(res, right->query(p, mid + 1, r)));
    }
} lct;
