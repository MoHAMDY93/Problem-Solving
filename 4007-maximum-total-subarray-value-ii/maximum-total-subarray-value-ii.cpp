const int N = 1e5;
class Solution {
private:
    int t_min[N][18], a[N];
    void build_min(int n) {
        for(int i = 1; i <= n; ++i) t_min[i][0] = a[i];
        for(int k = 1; k < 18; ++k) {
            for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
                t_min[i][k] = min(t_min[i][k - 1], t_min[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    int query_min(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(t_min[l][k], t_min[r - (1 << k) + 1][k]);
    }

    int t_max[N][18];
    void build_max(int n) {
        for(int i = 1; i <= n; ++i) t_max[i][0] = a[i];
        for(int k = 1; k < 18; ++k) {
            for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
                t_max[i][k] = max(t_max[i][k - 1], t_max[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    int query_max(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(t_max[l][k], t_max[r - (1 << k) + 1][k]);
    }
    
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        for (int i=1 ; i<=n ; i++) a[i] = nums[i-1];
        build_min(n) , build_max(n);
        priority_queue<array<int, 3>> pq;
        for (int l = 1; l <= n; l++) {
            int val = query_max(l, n) - query_min(l, n);
            pq.push({val , l , n});
        }
        long long ans = 0;
        while (k--) {
            auto [val , l , r] = pq.top();
            pq.pop();
            // cout << l << ' ' << r << ' ' << val << '\n';
            // cout << l << ' ' << r << '\n';
            // cout << query_max(l , r) << ' ' << query_min(l , r) << '\n';
            ans += val;
            if (r > l) {
                int nval = query_max(l, r-1) - query_min(l, r-1);
                pq.push({nval, l, r-1});
            }
        }
        return ans;
    }
};