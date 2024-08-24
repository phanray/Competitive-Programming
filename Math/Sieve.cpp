bool prime[maxn];

void sieve(int n){
    memset(prime, true, sizeof(prime[0])*(n+1));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j+=i)
                prime[j] = false;
        }
    }
}
