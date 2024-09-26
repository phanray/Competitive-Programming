const int maxc = 26;
const int firstc = 'a';

struct Aho_Corasick{
    struct node{
        int cnt, suffix_link, exit_link;
        int nxt[maxc], go[maxc];

        node(){
            for (int i = 0; i < maxc; i++) 
                nxt[i] = go[i] = -1;
            cnt = 0;
            suffix_link = exit_link = -1;
        }
    };
    vector<node> g = {node()};

    void insert(string s){
        int p = 0;
        for (auto c: s){
            if (g[p].nxt[c - firstc] == -1){
                g[p].nxt[c - firstc] = g.size();
                g.pb(node());
            }

            p = g[p].nxt[c - firstc];
        }
        g[p].cnt++;
    }

    void build_automaton(){
        queue<int>q;

        q.push(0);

        while(q.size()){
            int v = q.front(), suffix_link = g[v].suffix_link; q.pop();

            if (v)
                g[v].exit_link = (g[suffix_link].cnt ? suffix_link : g[suffix_link].exit_link);

            for (int i = 0; i < maxc; i++){
                int &nxt = g[v].nxt[i], nxt_suffix_link = (v ? g[suffix_link].nxt[i] : 0);

                if (nxt == -1)
                    nxt = nxt_suffix_link;
                else g[nxt].suffix_link = nxt_suffix_link, q.push(nxt);
            }
        }
    }

    void get_sindex(int p){
        for (int v = (g[p].cnt ? p : g[p].exit_link); v != -1; v = g[v].exit_link)
    }

    void solve(string t){
        for (int i = 0, p = 0; i < t.size(); i++){
            p = g[p].nxt[t[i] - firstc];

            get_sindex(p);
        }
    }

} aho;
