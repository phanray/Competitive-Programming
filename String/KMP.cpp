int pi[maxn];

void kmp(string s){
    for (i = 1; i < n; i++){
        j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])j++;
        
        pi[i] = j;
    }
}
