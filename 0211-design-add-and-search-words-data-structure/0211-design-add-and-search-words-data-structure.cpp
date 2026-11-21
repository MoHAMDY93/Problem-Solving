class WordDictionary {
private:
    struct node {
        node* children[26] = {nullptr};
        bool is_word = false;
    };
    node* root;
    bool dfs(node* curr, string& s, int i) {
        if (i == s.size()) return curr->is_word;
        if (s[i] != '.') {
            if (!curr->children[s[i] - 'a']) return false;
            return dfs(curr->children[s[i] - 'a'], s, i+1);
        }
        for (int c=0 ; c<26 ; c++) {
            if (curr->children[c] && dfs(curr->children[c], s, i+1)) 
                return true;
        }
        return false;
    }
public:
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* curr = root;
        for (auto c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */