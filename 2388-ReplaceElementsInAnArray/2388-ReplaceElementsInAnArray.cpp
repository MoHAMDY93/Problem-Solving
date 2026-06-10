// Last updated: 6/10/2026, 7:17:18 PM
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size();
        unordered_map<int , int> mp;
        for (int i=0 ; i<n ; i++) {
            mp[nums[i]] = i;
        }
        for (auto v : operations) {
            int idx = mp[v[0]];
            nums[idx] = v[1];
            mp[v[1]] = idx;
            mp.erase(v[0]);
        }
        return nums;
    }
};