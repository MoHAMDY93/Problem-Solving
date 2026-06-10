// Last updated: 6/10/2026, 7:23:53 PM
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<pair<char, char>, vector<char>> mp;
        for (auto &v : allowed) {
            mp[{v[0], v[1]}].push_back(v[2]);
        }

        unordered_map<string, bool> memo;

        function<bool(string, string, int)> dfs = [&](string cur, string nxtRow, int i) -> bool {
            if (cur.size() == 1) return true;  // reached the top
            if (i == cur.size() - 1) {
                // finished building this next row
                if (memo.count(nxtRow)) return memo[nxtRow];
                return memo[nxtRow] = dfs(nxtRow, "", 0);
            }

            auto p = make_pair(cur[i], cur[i + 1]);
            if (!mp.count(p)) return false;

            for (char c : mp[p]) {
                if (dfs(cur, nxtRow + c, i + 1)) return true;
            }
            return false;
        };

        return dfs(bottom, "", 0);
    }
};
