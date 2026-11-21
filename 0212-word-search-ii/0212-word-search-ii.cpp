struct node {
    bool isEnd = false;
    node* child[26] = {nullptr};
};
    
class Trie {
public:
    node* root;

    Trie() {
        root = new node();
    }

    void insert(string s) {
        node* nd = root;
        for (int i=0 ; i<s.size() ; i++) {
            if (!nd -> child[s[i] - 'a']) {
                nd -> child[s[i] - 'a'] = new node();
            }
            nd = nd -> child[s[i] - 'a'];
        }
        nd -> isEnd = true;
    }
    
    bool search(string s) {
        node* nd = root;
        for (int i=0 ; i<s.size(); i++) {
            if (!nd -> child[s[i] - 'a']) return false;
            nd = nd -> child[s[i] - 'a'];
        }
        return nd -> isEnd;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto s : words) trie.insert(s);

        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m , false));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        vector<string> ans;
        auto valid = [&](int x, int y) -> bool {
            return 0 <= x && x < n && 0 <= y && y < m && !vis[x][y];
        };
        auto dfs = [&](this auto&& dfs, int x, int y, node* curr, string& word) -> void {
            if (curr -> isEnd) {
                ans.push_back(word);
                curr->isEnd = false;    
            }
            int c = board[x][y] - 'a';
            for (int d=0 ; d<4 ; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (valid(nx, ny) && curr -> child[board[nx][ny] - 'a']) {
                    vis[nx][ny] = true;
                    word.push_back(board[nx][ny]);
                    node* tmp = curr -> child[board[nx][ny] - 'a'];
                    dfs(nx, ny, tmp, word);
                    word.pop_back();
                    vis[nx][ny] = false;
                }
            }
        };
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                int c = board[i][j] - 'a';
                if (trie.root -> child[c]) {
                    string word = string(1, board[i][j]);
                    vis[i][j] = true;
                    dfs(i, j, trie.root->child[c], word);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
};