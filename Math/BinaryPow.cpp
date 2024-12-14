ll sqr(ll x){
	return x * x % mod;
}

ll BinaryPow(ll a, ll b){
	if (b == 0)
		return 1;

	if (b % 2)
		return sqr(BinaryPow(a, b >> 1)) * a % mod;

	return sqr(BinaryPow(a, b >> 1));
}
