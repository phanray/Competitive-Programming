struct Matrix{
    vector<vector<ll> >a;

    Matrix(int n, int m): a(n, vector<ll> (m)){}

    Matrix(const vector<vector<ll> >&b): a(b){}

    int row() const {return a.size();}

    int col() const {return a[0].size();}

    auto & operator [] (int i) {return a[i];}

    const auto & operator[] (int i) const {return a[i];}

    Matrix identity(ll n){
        Matrix a = Matrix(n, n);

        while (n--) 
            a[n][n] = 1;

        return a;
    }

    Matrix operator * (const Matrix &b) {
        assert(col() == b.row());
        Matrix c(row(), b.col());

        for (int i = 0; i < row(); ++i)
            for (int j = 0; j < b.col(); ++j)
                for (int k = 0; k < col(); ++k)
                    (c[i][j] += a[i][k] * b[k][j]) %= mod;

        return c;
    }

    Matrix pow(ll x){
        assert(row() == col());
        Matrix base = *this, ans = identity(row());

        for (; x > 0; x >>= 1, base = base * base)
            if (x & 1) 
                ans = ans * base;

        return ans;
    }
};
