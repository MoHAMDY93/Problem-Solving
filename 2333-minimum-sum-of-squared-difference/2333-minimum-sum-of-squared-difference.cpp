class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long ans = 0 , k = k1 + k2;
        int mx = 0;
        for (int i=0 ; i<n ; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx , nums1[i]);
        }
        auto check = [&](int mid) -> bool {
            long long sum = 0;
            for (auto num : nums1) {
                sum += num > mid ? num - mid : 0;
            }
            return sum <= k;
        };
        int l = 0 , r = mx , best = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) best = mid , r = mid - 1;
            else l = mid + 1;
        }
        for (auto num : nums1) {
            if (num > best) k -= (num - best);
        }
        sort(rbegin(nums1) , rend(nums1));
        for (auto num : nums1) {
            long long diff = best >= num ? num : best;
            if (k && diff) {
                diff-- , k--;
            }
            // cout << num << ' ' << diff << ' ' << k << '\n';
            ans += diff * diff;
        }
        return ans;
    }
};