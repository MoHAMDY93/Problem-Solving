// Last updated: 6/10/2026, 7:15:39 PM
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, vector<int>> indexMap;

        // Group indices by their values
        for (int i = 0; i < n; ++i) {
            indexMap[nums[i]].push_back(i);
        }

        // Process each group of indices
        for (auto const& [val, indices] : indexMap) {
            int k = indices.size();
            if (k <= 1) continue;

            // Calculate total sum of indices for this group
            long long totalSum = 0;
            for (int idx : indices) {
                totalSum += idx;
            }

            long long prefixSum = 0;
            for (int i = 0; i < k; ++i) {
                long long currentIdx = indices[i];
                
                // Formula: (Left side distances) + (Right side distances)
                // Left:  (i * currentIdx) - (sum of indices before current)
                // Right: (sum of indices after current) - ((k - 1 - i) * currentIdx)
                
                long long leftDist = (1LL * i * currentIdx) - prefixSum;
                
                long long suffixSum = totalSum - prefixSum - currentIdx;
                long long rightDist = suffixSum - (1LL * (k - 1 - i) * currentIdx);
                
                arr[currentIdx] = leftDist + rightDist;
                
                // Update prefixSum for the next element in the group
                prefixSum += currentIdx;
            }
        }

        return arr;
    }
};