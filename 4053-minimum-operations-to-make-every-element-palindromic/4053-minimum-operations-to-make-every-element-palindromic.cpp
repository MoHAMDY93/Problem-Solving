class Solution {
private:
    inline static vector<long long> pals_even , pals_odd;
    static void gen() {
        for (int len = 1; len <= 9; len++) {
            int halfLen = (len + 1) / 2;

            int start = pow(10, halfLen - 1);
            int end = pow(10, halfLen) - 1;

            for (int half = start; half <= end; half++) {
                string s = to_string(half);
                string t = s;

                // For odd length, don't duplicate the middle digit
                int i = (len % 2 == 1 ? s.size() - 2 : s.size() - 1);

                for (; i >= 0; i--)
                    t += s[i];

                long long x = stoll(t);

                if (x <= 1e9)
                    (x & 1 ? pals_odd : pals_even).push_back(x);
            }
        }
    }

public:
    Solution() {
        static bool init = false;
        if (!init) {
            init = true;
            gen();
        }
    }
    long long minOperations(vector<int>& nums) {
        long long ans = 0;
        for (int i : nums) {
            const auto& pals = (i & 1 ? pals_odd : pals_even);
            auto it = lower_bound(pals.begin(), pals.end(), i);
            long long left = LLONG_MAX;
            long long right = LLONG_MAX;
            // palindrome < i
            if (it != pals.begin()) {
                left = i - *prev(it);
            }
            if (it != pals.end()) {
                right = *it - i;
            }
            ans += min(left / 2, right / 2);
        }
        return ans;
    }
};