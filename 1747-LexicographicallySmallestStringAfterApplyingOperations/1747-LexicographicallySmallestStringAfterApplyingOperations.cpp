// Last updated: 6/10/2026, 7:20:10 PM
class Solution {
public:
    int n;
    void add(string& s, int a) {
        for (int i = 1; i < n; i += 2)
            s[i] = '0' + ((s[i] - '0' + a) % 10);
    }

    string rotate(const string& s, int b) {
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        n = s.size();
        unordered_set<string> vis;
        vis.insert(s);
        string ans = s;
        deque<string> dq = {s};

        while (!dq.empty()) {
            string cur = dq.front(); dq.pop_front();
            ans = min(ans, cur);

            string t1 = rotate(cur, b);
            if (!vis.count(t1)) {
                vis.insert(t1);
                dq.push_back(t1);
            }

            string t2 = cur;
            add(t2, a);
            if (!vis.count(t2)) {
                vis.insert(t2);
                dq.push_back(t2);
            }
        }
        return ans;
    }
};