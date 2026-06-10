// Last updated: 6/10/2026, 7:27:31 PM
class Solution {
public:
    int memo[1000005] = {};
    long long test(int pos , vector<int>& nums) {
        if(memo[pos] != 0)
            return memo[pos];
        int n = nums.size();
        if(pos >= n-1)
            return 0;
        int MinJumps = INT_MAX;
        int MaxJumps = min(nums[pos] , n - pos - 1);
        for(int i=1 ; i <= MaxJumps ; i++) {
            long long jumps = 1 + test(pos + i , nums);
            if(jumps < MinJumps)
                MinJumps = jumps;
        }
        memo[pos] = MinJumps; 
        return MinJumps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        return test(0 , nums);
    }
};