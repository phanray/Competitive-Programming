#include<bits/stdc++.h>

using namespace std;

#define el "\n"
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define inpout(a) freopen(a".inp","r",stdin),freopen(a".out","w",stdout)

template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll a,ll b) {
     return uniform_int_distribution<int>(a,b)(rd);
}

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

int n, i;
int a[maxn];

signed main(){
	ios;
	cin >> n;
}