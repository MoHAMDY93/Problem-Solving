#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Reverse the array so that suffix maximums in the reversed array 
        // correspond to prefix maximums in the original array.
        reverse(nums.begin(), nums.end());

        deque<pair<int, int>> dq; // {value, count}

        long long invalid = 0;
        int l = 0;

        long long sum = 0, sum_max = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];
            int cnt = 1;

            // Maintain decreasing monotonic queue
            while (!dq.empty() && dq.back().first <= nums[r]) {
                sum_max -= 1LL * dq.back().first * dq.back().second;
                cnt += dq.back().second;
                dq.pop_back();
            }

            dq.push_back({nums[r], cnt});
            sum_max += 1LL * nums[r] * cnt;

            // Shrink window if operations needed exceed k
            while (sum_max - sum > k) {
                invalid += n - r; // All subarrays starting from l and ending at r or later are invalid
                sum -= nums[l];

                // Remove the leftmost position's contribution
                dq.front().second--;
                sum_max -= dq.front().first;

                if (dq.front().second == 0) {
                    dq.pop_front();
                }

                l++;
            }
        }

        // Total subarrays - invalid subarrays
        return 1LL * n * (n + 1) / 2 - invalid;
    }
};