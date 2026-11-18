class Trie {
private:
    struct node {
        bool isEnd;
        node* child[26];
    };
    node* root;
    
    node* create() {
        node* nd = new node();
        for (int i=0 ; i<26 ; i++) {
            nd -> child[i] = NULL;
        }
        nd -> isEnd = false;
        return nd; 
    }

public:
    Trie() {
        root = create();
    }
    
    void insert(string s) {
        node* nd = root;
        for (int i=0 ; i<s.size() ; i++) {
            if (nd -> child[s[i] - 'a'] == NULL) {
                nd -> child[s[i] - 'a'] = create();
            }
            nd = nd -> child[s[i] - 'a'];
        }
        nd -> isEnd = true;
    }
    
    bool search(string s) {
        node* nd = root;
        for (int i=0 ; i<s.size(); i++) {
            if (nd -> child[s[i] - 'a'] == NULL) return false;
            nd = nd -> child[s[i] - 'a'];
        }
        return nd -> isEnd;
    }
    
    bool startsWith(string s) {
        node* nd = root;
        for (int i=0 ; i<s.size(); i++) {
            if (nd -> child[s[i] - 'a'] == NULL) return false;
            nd = nd -> child[s[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */