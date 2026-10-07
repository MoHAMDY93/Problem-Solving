class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        auto valid = [&](string& ss) -> bool {
            int bal = 0;
            for (auto c : ss) {
                if (c == '(') bal++;
                else if (c == ')') {
                    bal--;
                    if (bal < 0) return false;
                }
            }
            return (bal == 0);
        };
        queue<string> q;
        unordered_set<string> vis;
        bool done = false;
        vector<string> ans; 

        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string ss = q.front(); q.pop();
            // cout << ss << endl;
            if (valid(ss)) {
                // cout << "in\n";
                ans.push_back(ss);
                done = true;
                continue;
            }
            if (done) continue;
            for (int i=0 ; i<ss.size() ; i++) {
                if (ss[i] != '(' && ss[i] != ')') continue;
                if (i > 0 && ss[i] == ss[i-1]) continue;
                string nxt = ss.substr(0 , i) + ss.substr(i+1);
                // cout << "nxt:: " << nxt << endl;
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        return ans;
    }
};