vector<int>prime, prime_pw, phi, rem;
vector<vector<ll>>fact, ifact;
ll mod, d;

ll binpow(ll a, ll n, ll mod){
    ll res = 1;
    for (; n > 0; n >>= 1)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

void init(int x){
    fact[x].assign(prime_pw[x], 0);
    ifact[x].assign(prime_pw[x], 0);
    fact[x][0] = 1;
    for (int i = 1; i < prime_pw[x]; i++)
    {
        if (i % prime[x] != 0)
            fact[x][i] = (fact[x][i - 1] * i) % prime_pw[x];
        else
            fact[x][i] = fact[x][i - 1];
    }
    ifact[x][prime_pw[x] - 1] = binpow(fact[x][prime_pw[x] - 1],
                                        prime_pw[x] / prime[x] * (prime[x] - 1) - 1,
                                        prime_pw[x]);
    for (int i = prime_pw[x] - 1; i > 0; i--)
    {
        if (i % prime[x] != 0)
            ifact[x][i - 1] = (ifact[x][i] * i) % prime_pw[x];
        else
            ifact[x][i - 1] = ifact[x][i];
    }
}

ll C(ll N, ll K, ll R, int i){
    return (fact[i][N] * ifact[i][R] % prime_pw[i]) * ifact[i][K] % prime_pw[i];
}

int count_carry(ll n, ll k, ll r, ll p, ll t){
    ll res = 0;
    while (n >= t){
        res += (n / t - k / t - r / t);
        t *= p;
    }
    return res;
}

ll calc(ll N, ll K, ll R, int ord_pr){
    if (K > N)
        return 0;
    int pri = prime[ord_pr];
    int mod = prime_pw[ord_pr];
    ll res = 1;
    int vp = count_carry(N, K, R, pri, pri);
    int vp2 = count_carry(N, K, R, pri, mod);
    while (N > 0)
    {
        res = (res * C(N % mod, K % mod, R % mod, ord_pr)) % mod;
        N /= pri;
        K /= pri;
        R /= pri;
    }
    res = res * binpow(pri, vp, mod) % mod;
    if ((vp2 & 1) && (pri != 2 || mod <= 4))
        res = (mod - res) % mod;

    return res;
}

ll CRT(ll N, ll K){
    ll res = 0;
    for (int i = 0; i < d; i++){
        int ans = calc(N, K, N - K, i) * rem[i] % mod;
        res = (res + ans) % mod;
    }
    return res;
}

void prepare(ll x){
    ll i = 2;

    while(i * i <= x){
        if (x % i == 0){
            d++;
            prime.pb(i);
            prime_pw.pb(1);

            while(x % i == 0)
                prime_pw.back() *= i, x /= i;
        }
        i++;
    }

    if (x != 1){
        d++;
        prime.pb(x);
        prime_pw.pb(x);
    }

    phi.resize(d, 0);
    rem.resize(d, 0);
    fact.resize(d, vector<ll>(0, 0));
    ifact.resize(d, vector<ll>(0, 0));

    for (int i = 0; i < d; i++){
        init(i);
        int tmp = mod / prime_pw[i];
        phi[i] = prime_pw[i] / prime[i] * (prime[i] - 1);
        rem[i] = tmp * binpow(tmp, phi[i] - 1, prime_pw[i]) % mod;
    }
}
