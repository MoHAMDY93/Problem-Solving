// Last updated: 6/10/2026, 7:17:46 PM
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size(), k = n / 3;
        vector<long long> left(n), right(n+1);

        // 1) Build left[]: for each i, sum of k smallest replacements
        priority_queue<int> maxHeap;
        long long sum = 0;
        // first k elements: take them all
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            maxHeap.push(nums[i]);
        }
        left[k-1] = sum;
        // for i = k .. 2k-1, consider nums[i] joining the left-segment window
        for (int i = k; i < 2*k; ++i) {
            sum += nums[i];
            maxHeap.push(nums[i]);
            // eject the largest to keep exactly k elements
            sum -= maxHeap.top();
            maxHeap.pop();
            left[i] = sum;
        }

        // 2) Build right[] backwards: sum of k largest replacements
        //    within nums[i..n-1], we want the k **smallest** sum => we keep a min‐heap of size k
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        // last k elements
        for (int i = n-1; i >= n-k; --i) {
            sum += nums[i];
            minHeap.push(nums[i]);
        }
        right[n-k] = sum;
        // for i = n-k-1 down to k:
        for (int i = n-k-1; i >= k; --i) {
            sum += nums[i];
            minHeap.push(nums[i]);
            // eject the smallest to keep exactly k elements
            sum -= minHeap.top();
            minHeap.pop();
            right[i] = sum;
        }

        // 3) Combine
        long long ans = LLONG_MAX;
        // split between i and i+1, where left uses [0..i], right uses [i+1..n-1]
        // valid i runs from k-1 up to 2k-1
        for (int i = k-1; i < 2*k; ++i) {
            ans = min(ans, left[i] - right[i+1]);
        }
        return ans;
    }

};