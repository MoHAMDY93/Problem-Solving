// Last updated: 6/10/2026, 7:15:47 PM
class Solution {
private:
    int bs(vector<int>& a , int value , int curr) {
        int n = a.size() , l = curr + 1 , r = n-1 , out = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[curr] + a[m] >= value){
                out = m;
                r = m-1;
            }
            else 
                l = m+1;
        }
        return out;
    }
    int bl(vector<int>& a , int value , int curr) {
        int n = a.size() , l = curr + 1 , r = n-1 , out = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[curr] + a[m] <= value){
                out = m;
                l = m+1;
            }
            else 
                r = m-1;
        }
        return out;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        long long cnt = 0;
        for(int i=0 ; i<n ; i++) {
            auto lower_it = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            // Find last element where nums[i] + nums[j] <= upper
            auto upper_it = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            
            if (lower_it != nums.end() && upper_it != nums.begin() + i + 1) {
                cnt += (upper_it - nums.begin()) - (lower_it - nums.begin());
            }
        }
        return cnt;
    }
};