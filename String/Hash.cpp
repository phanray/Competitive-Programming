const long long base = 311;
const long long mxSize = 1e6 + 100;
const long long modHash[4] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
const long long nMod = 2;
long long pw[mxSize][nMod];

void precalcHash(int sz, int szMod) {

    for (int i = 0; i < szMod; i++)
        pw[0][i] = 1;
    for (int i = 1; i < sz; i++)
        for (int j = 0; j < szMod; j++)
            (pw[i][j] = pw[i - 1][j] * base) %= modHash[j];
}

struct HashString {

    vector<vector<long long>> hashVal;

    void buildHash(string s) {

        int n = s.size();
        hashVal.resize(n + 1);
        for (int i = 0; i <= n; i++)
            hashVal[i].resize(nMod);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < nMod; j++)
                (hashVal[i][j] = hashVal[i - 1][j] * base + int(s[i - 1])) %= modHash[j];
        }
    }

    long long getHash(int l, int r, int pos) {

        return (hashVal[r][pos] - hashVal[l - 1][pos] * pw[r - l + 1][pos] + modHash[pos] * modHash[pos]) % modHash[pos];
    }
};
