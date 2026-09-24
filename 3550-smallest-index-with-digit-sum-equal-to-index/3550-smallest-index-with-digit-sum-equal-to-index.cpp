class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        auto sum = [&](int x) -> int {
            int sum = 0;
            for ( ; x ; x /= 10) sum += x % 10; 
            return sum; 
        };
        for (int i=0 ; i<nums.size() ; i++) {
            if (sum(nums[i]) == i) return i;
        }
        return -1;
    }
};