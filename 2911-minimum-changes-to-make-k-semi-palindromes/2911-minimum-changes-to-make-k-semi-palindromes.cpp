class Solution {
private:
    const int INF = 205;
    int get_diff(string& t) {
        int cnt = 0;
        for (int l=0, r = t.size()-1 ; l < r ; l++, r--) {
            cnt += t[l] != t[r];
        }
        return cnt;
    }
    int get_cost(string& s, int l, int r) {
        int sz = r - l + 1;
        if (sz == 1) return INF;
        int mn = INF;
        vector<int> divs;
        for (int d = 1; d * d <= sz; d++) {
            if (sz % d == 0) {
                divs.push_back(d);
                if (d != 1 && sz / d != d) divs.push_back(sz / d);
            }
        }
        for (int d : divs) {
            int curr_cost = 0;
            for (int offset = 0; offset < d; offset++) {
                string t;
                for (int i = l + offset; i <= r; i += d) {
                    t.push_back(s[i]);
                }
                curr_cost += get_diff(t);
            }
            mn = min(mn, curr_cost);
        }
        return mn;
    }
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        // Precompute substring costs once
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                cost[l][r] = get_cost(s, l, r);
            }
        }
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (n, vector<int> (k+1 , -1)));
        auto dp = [&](this auto&& dp, int l, int r, int cnt) -> int {
            if (r == n-1) {
                if (cnt == k-1) return cost[l][r];
                return INF;
            } 
            if (cnt >= k) return INF;
            auto& ret = memo[l][r][cnt];
            if (~ret) return ret;
            ret = dp(l, r+1, cnt);
            if (cost[l][r] < INF)
                ret = min(ret, cost[l][r] + dp(r+1, r+1, cnt+1));
            return ret;
        };
        return dp(0 , 0 , 0);
    }
};