class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i=0 ; i<n ; i++) {
            int avg = 0, cnt = 0;
            if (i-1 >= 0) avg += nums[i-1], cnt++;
            if (i+1 < n) avg += nums[i+1], cnt++;
            if (!cnt || nums[i] * cnt >= avg) ans++;
        }
        return ans;
    }
};