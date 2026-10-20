class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divs;
        for (int d = 1 ; d * d <= n ; d++) {
            if (n % d == 0) {
                divs.push_back(d);
                if (n / d != d) divs.push_back(n / d);
            }
        }
        sort(begin(divs) , end(divs));
        vector<int> sorted(begin(nums) , end(nums));
        sort(begin(sorted) , end(sorted));
        
        auto check = [&](int l, int r) -> bool {
            int n = r - l + 1;

            // Build LPS for sorted[l...r], using relative indices
            vector<int> lps(n, 0);

            for (int i = 1, len = 0; i < n; ) {
                if (sorted[l + i] == sorted[l + len]) {
                    lps[i++] = ++len;
                } else if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }

            // Search sorted[l...r] in the cyclic version of nums[l...r]
            for (int i = 0, j = 0; i < 2 * n - 1; ) {
                if (nums[l + (i % n)] == sorted[l + j]) {
                    i++;
                    j++;

                    if (j == n) return true;
                } else if (j > 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }

            return false;
        };
        int ans = 0;
        for (int d : divs) {
            bool ok = true;
            for (int l=0 ; l < n ; l += d) {
                int r = l + d - 1;
                if (!check(l , r)) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans += d;
        }
        return ans;
    }
};