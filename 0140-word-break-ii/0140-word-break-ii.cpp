enum class TrieMode { Lowercase, Uppercase, Digits };
template < TrieMode Mode >
class Trie {
public:
    Trie() : root(new Node()) {}

    void insert(const string& word) {
        Node* curr = root;
        for (char c : word) {
            int index = charToIndex(c);
            if (!curr -> children[index]) 
                curr -> children[index] = new Node();
            curr = curr -> children[index];
            curr -> freq++;
        }
        curr -> is_word = true;
    }

    bool search(const string& word) const {
        const Node* curr = root;
        for (char c : word) {
            int index = charToIndex(c);
            if (!curr -> children[index]) return false;
            curr = curr -> children[index];
        }
        return curr -> is_word;
    }

    void erase(const string& word) {
        erase(word, 0, root);
    }

    bool is_prefix(const string& word) const {
        const Node* curr = root;
        for (char c : word) {
            int index = charToIndex(c);
            if (!curr -> children[index]) return false;
            curr = curr -> children[index];
        }
        return true;
    }
    
    int get_freq(const string& word) const {
        const Node* curr = root;
        for (char c : word) {
            int index = charToIndex(c);
            if (!curr -> children[index]) return 0;
            curr = curr -> children[index];
        }
        return curr -> freq;
    }
private:
    inline static constexpr int charSize() {
        switch (Mode) {
            case TrieMode::Lowercase: return 26;
            case TrieMode::Uppercase: return 26;
            case TrieMode::Digits:    return 10;
        }
        return 0; // Should never reach here
    }

    inline static int charToIndex(char c) {
        switch (Mode) {
            case TrieMode::Lowercase: return c - 'a';
            case TrieMode::Uppercase: return c - 'A';
            case TrieMode::Digits:    return c - '0';
        }
        return -1; // Should never reach here
    }

        struct Node {
            Node* children[charSize()] = {nullptr};
            bool is_word = false;
            int freq = 0;
        };

    Node* root;

    void erase(const std::string& word, size_t idx, Node* curr) {
        if (idx == word.size()) return curr -> is_word = false, void();
        int index = charToIndex(word[idx]);
        if (curr -> children[index]) {
            erase(word, idx + 1, curr -> children[index]);
            curr -> children[index] -> freq--;
            if (curr -> children[index] -> freq == 0) {
                delete curr -> children[index];
                curr -> children[index] = nullptr;
            }
        }
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie<TrieMode::Lowercase> trie;
        for (auto& w : wordDict) trie.insert(w);
        int n = s.size();
        vector<vector<bool>> ok(n, vector<bool> (n, false));
        for (int l=0; l<n ; l++) {
            for (int r=0; r<n ; r++) {
                if (trie.search(s.substr(l, r-l+1))) ok[l][r] = true;
            }
        }  
        vector<string> valid;
        auto get = [&](this auto&& get, int l, int r, string& curr) -> void {
            string t = s.substr(l, r-l+1);
            // base case
            if (r == n-1) {
                if (ok[l][r]) {
                    curr.append(t);
                    valid.push_back(curr);
                }
                return;
            }
            if (ok[l][r]) {
                int oldSize = curr.size();
                curr += t + " ";
                get(r + 1, r + 1, curr);
                curr.resize(oldSize);
            }
            get(l, r+1, curr); 
        };
        string curr = "";
        get(0, 0, curr);
        return valid;
    }
};