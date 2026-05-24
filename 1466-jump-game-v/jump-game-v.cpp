class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> best(n , -1);
        auto dfs  = [&](this auto&& dp , int i) -> int {
            auto& ret = best[i];
            if (~ret) return ret;
            ret = 0;
            bool ok_right = true , ok_left = true;
            for (int j=1 ; j<=d ; j++) {
                if (i + j < n && ok_right) {
                    if (arr[i+j] < arr[i])
                        ret = max(ret , dp(i + j) + 1);
                    else 
                        ok_right = false;
                }
                if (i - j >= 0 && ok_left) {
                    if (arr[i-j] < arr[i])
                        ret = max(ret , dp(i - j) + 1);
                    else 
                        ok_left=  false;
                }
            }
            // cout << i << ' ' << ret << '\n';
            return ret;
        };
        for (int i=0 ; i<n ; i++) dfs(i);
        return *max_element(best.begin() , best.end()) + 1;
    }
};