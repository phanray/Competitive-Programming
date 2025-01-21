ll fac[maxn], finv[maxn], inv[maxn];

ll C(ll n, ll k) {
    if (n < k)
        return 0;

    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

void prepare(int n) {
    fac[0] = finv[0] = inv[0] = 1;
    fac[1] = finv[1] = inv[1] = 1;

    for (int i = 2; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = (mod - (mod / i * inv[mod % i] % mod)) % mod;        
        finv[i] = (finv[i - 1] * inv[i]) % mod;
    }
}
