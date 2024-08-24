stack<int>st;
int cnt,res,tmp,low[maxn],num[maxn];

void tarjan(int u){
    low[u] = num[u] = ++cnt;
    st.push(u);

    for (auto v: a[u]){
        if (num[v]) 
            low[u] = min(low[u], num[v]);
        else{
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (num[u] == low[u]){
        res++;
        do{
            tmp = st.top(); st.pop();

            num[tmp] = low[tmp] = INT_MAX;
        }while (u != tmp);
    }
}
