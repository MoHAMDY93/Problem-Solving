// Last updated: 6/10/2026, 7:10:50 PM
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        unordered_map<int, int> freq;
        int mx = 0;
        for(int num : nums) {
            freq[num]++;
            mx = max(mx, freq[num]);
        }
        int groups = n / k;
        return mx <= groups;
    }

};