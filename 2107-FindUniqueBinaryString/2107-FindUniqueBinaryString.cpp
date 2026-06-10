// Last updated: 6/10/2026, 7:18:46 PM
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int n = nums.size();
        for (int i=0 ; i<n ; i++) {
            ans.push_back(nums[i][i] == '0' ? '1' : '0');
        }
        return ans;
    }
};