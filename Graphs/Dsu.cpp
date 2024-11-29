struct Dsu{
    int p[maxn], s[maxn];

    void init(int n){
        for (int i = 1; i <= n; ++i)
            p[i] = i, s[i] = 1;
    }

    int find(int v){
        return v == p[v] ? v : p[v] = find(p[v]);
    }

    void uni(int a, int b){
        a = find(a);
        b = find(b);
        
        if (a != b) {
            if (s[a] < s[b]) 
                swap(a,b);
            
            p[b] = a;
            s[a] += s[b];
        }
    }
}dsu;
