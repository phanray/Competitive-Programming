struct Trie {

    struct TrieNode {

        int cnt, exist;
        TrieNode *child[26];

        TrieNode(){
            cnt = exist = 0;

            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }

    } *root = new TrieNode();

    void add(string s) {
        TrieNode *Node = root;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (Node->child[c] == NULL)
                Node->child[c] = new TrieNode();

            Node = Node->child[c];
            Node->cnt++;
        }

        Node->exist++;
    }

    bool find(string s) {

        TrieNode *Node = root;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (Node->child[c] == NULL)
                return false;

            Node = Node->child[c];
        }

        return Node->exist;
    }

} Trie;
