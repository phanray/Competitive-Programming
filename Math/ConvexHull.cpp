#include<bits/stdc++.h>

using namespace std;

#define el "\n"
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inpout(a) freopen(a".inp","r",stdin),freopen(a".out","w",stdout)

struct point{
    ll x, y;
};

const int maxn = 1e5 + 1;

int n, i, m, ans;
point a[maxn];
vector<point>hull;

bool cmp(point a, point b){
    if (a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

ll cross(point A, point B, point C) {
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y);
}

int goc(point A, point B, point C) {
    ll S = cross(A, B, C);
    if (S < 0) return -1;
    if (S == 0) return 0;
    return 1;
}

bool inTriangle(point a, point b, point c, point q){
    ll s1 = cross(a, b, q);
    ll s2 = cross(b, c, q);
    ll s3 = cross(c, a, q);

    return max({s1, s2, s3}) <= 0 || min({s1, s2, s3}) >= 0;
}

bool check(point q){
    int l = 2, r = n - 1, p = 1;

    while(l <= r){
        int mid = l + r >> 1;

        if (cross(hull[0], hull[mid], q) > 0)
            p = mid, l = mid + 1;
        else r = mid - 1;
    }

    return (p + 1 < n && inTriangle(hull[0], hull[p], hull[p + 1], q));
}

int main(){
    ios;
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    for (int i = 1; i < n; ++i) {
        if (a[0].y > a[i].y || (a[0].y == a[i].y && a[0].x > a[i].x)) {
            swap(a[0], a[i]);
        }
    }

    sort(a + 1, a + n, [&](const point &A, const point &B) {
        int c = goc(a[0], A, B);
        if (c > 0) return true;
        if (c < 0) return false;
        return A.x < B.x || (A.x == B.x && A.y < B.y);
    });

    hull.push_back(a[0]);

    for (int i = 1; i < n; ++i) {
        while (hull.size() >= 2 && goc(hull[hull.size() - 2], hull.back(), a[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(a[i]);
    }
    while(hull.size() > 1 && goc(hull[hull.size() - 2], hull.back(), a[0]) <= 0)
        hull.pop_back();

    n = (int)hull.size();

    cin >> m;

    for (i = 0; i < m; i++){
        point q;
        cin >> q.x >> q.y;

        if (check(q))
            ans++;
    }

    cout << ans;
}
