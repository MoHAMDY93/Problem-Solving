// Last updated: 6/10/2026, 7:22:07 PM
constexpr int MX = 100'001;
int divisor_num[MX];
int divisor_sum[MX];

int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) { 
            divisor_num[j]++;
            divisor_sum[j] += i;
        }
    }
    return 0;
}();

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            if (divisor_num[x] == 4) {
                ans += divisor_sum[x];
            }
        }
        return ans;
    }
};