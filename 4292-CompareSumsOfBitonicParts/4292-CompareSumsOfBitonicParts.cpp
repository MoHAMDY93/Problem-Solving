// Last updated: 6/10/2026, 7:07:55 PM
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int mx = *max_element(nums.begin() , nums.end());
        long long sum1 = 0 , sum2=  0;
        int i = 0;
        for (; nums[i] != mx ; i++) sum1 += nums[i];
        i++;
        for (; i < nums.size() ; i++) sum2 += nums[i];
        if (sum1 > sum2) return 0;
        else if (sum1 < sum2) return 1;
        else return -1;
    }
};