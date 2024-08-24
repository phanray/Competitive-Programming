// Trie Tree

struct TrieNode {

    TrieNode *child[26];
    int cnt;
    TrieNode()
    {

        cnt = 0;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }

} *root = new TrieNode();

struct Trie {

    void Insert(string s) {

        TrieNode *Node = root;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (Node->child[s[i] - 'a'] == NULL)
                Node->child[s[i] - 'a'] = new TrieNode();
            Node = Node->child[s[i] - 'a'];
        }

        Node->cnt++;
    }

    void Find(string s) {

        TrieNode *Node = root;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            // if (Node->child[s[i]-'a']==NULL) return;
            // Node = Node->child[s[i]-'a'];
        }
    }

} Trie;
