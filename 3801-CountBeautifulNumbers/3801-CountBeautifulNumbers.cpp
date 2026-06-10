// Last updated: 6/10/2026, 7:12:00 PM
// Move the massive array entirely off the stack to avoid stack overflows.
// We store a pair: {visited_test_id, calculated_result}
static pair<int, int> memo[11][91][91][91][2][2];
static int current_test_id = 0;

class Solution {
public:
    int calc(string& s) {
        auto dp = [&](this auto&& dp, int idx, int target_sum, int sum, int prod_rem, int small, int start) -> int {
            if (idx == s.size()) {
                return (start && sum == target_sum && prod_rem == 0);
            }
            
            if (sum > target_sum) return 0;
            if (sum + (int)(s.size() - idx) * 9 < target_sum) return 0;

            // Check if this state has been visited during the CURRENT test iteration
            auto& cell = memo[idx][target_sum][sum][prod_rem][small][start];
            if (cell.first == current_test_id) {
                return cell.second;
            }

            int ed = small ? 9 : s[idx] - '0';
            int ans = 0;

            for (int d = 0; d <= ed; d++) {
                int nsum = sum + d;
                int nsmall = small || (d < s[idx] - '0');
                int nstart = start || (d > 0);
                
                int nprod_rem = prod_rem;
                if (nstart) {
                    if (!start) nprod_rem = d % target_sum;
                    else nprod_rem = (prod_rem * d) % target_sum;
                }

                ans += dp(idx + 1, target_sum, nsum, nprod_rem, nsmall, nstart);
            }

            // Save the result marked with the current test session identifier
            cell.first = current_test_id;
            return cell.second = ans;
        };

        int total = 0;
        for (int target_sum = 1; target_sum <= 90; target_sum++) {
            total += dp(0, target_sum, 0, 0, 0, 0);
        }
        return total;
    }

    int beautifulNumbers(int l, int r) {
        string L = to_string(l - 1); 
        string R = to_string(r);
        
        // Advance the test ID instead of running a heavy memset() operation.
        // This instantly invalidates old cached states.
        current_test_id++;
        int ans_r = calc(R);
        
        current_test_id++;
        int ans_l = calc(L);
        
        return ans_r - ans_l;
    }
};