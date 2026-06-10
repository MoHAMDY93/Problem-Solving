// Last updated: 6/10/2026, 7:18:34 PM
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin() , nums.end() , 0);
        vector<vector<int>> left(n+1) , right(n+1);
        vector<int> L(nums.begin() , nums.begin() + n);
        vector<int> R(nums.begin() + n , nums.end());
        for (int mask=0 ; mask<(1 << n) ; mask++) {
            int cnt = __builtin_popcount(mask);
            int A=0 , B=0;
            for (int i=0 ; i<n ; i++) {
                if ((mask >> i) & 1) A += L[i] , B += R[i];
            }
            left[cnt].push_back(A) , right[cnt].push_back(B);
        }
        // cout << left.size() << ' ' << right.size() << '\n';
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }
        for (int i = 0; i <= n; i++) {
            auto &vec = right[n - i];
            for (auto A : left[i]) {
                int target = total / 2 - A;
                auto it = lower_bound(vec.begin(), vec.end(), target);
                if (it != vec.end()) {
                    ans = min(ans, abs(total - 2 * (A + *it)));
                }
                if (it != vec.begin()) {
                    --it;
                    ans = min(ans, abs(total - 2 * (A + *it)));
                }
            }
        }
        return ans;
    }
};