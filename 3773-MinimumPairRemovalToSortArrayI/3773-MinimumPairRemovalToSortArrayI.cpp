// Last updated: 6/10/2026, 7:12:12 PM
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        if(nums == vec) return 0;

        int count = 0;
        while(1 > 0)
        {
        int minsum = INT_MAX;
        int st = 0, ed = 0;
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(minsum > (nums[i] + nums[i + 1]))
            {
                minsum = (nums[i] + nums[i + 1]);
                st = i;
                ed = i + 1;
            }
        }
        nums[st] = minsum;
        count++;
        nums.erase(nums.begin() + ed);
        vector<int> v = nums;
        sort(v.begin(), v.end());
        if(v == nums) return count;
        }
        return 0;
    }
};