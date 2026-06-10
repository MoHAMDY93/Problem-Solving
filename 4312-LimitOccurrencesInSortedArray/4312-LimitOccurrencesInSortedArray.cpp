// Last updated: 6/10/2026, 7:07:51 PM
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
         map<int , int> mp , mp2;
        for (int i : nums) mp[i]++;
        vector<int> ans;
        for (auto [val , cnt] : mp) {
            while (mp2[val]++ < k) {
                ans.push_back(val);
                cnt--;
                if (cnt == 0) break;
            }
        }
        return ans;
    }
};