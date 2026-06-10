// Last updated: 6/10/2026, 7:21:54 PM
class Solution {

public:

    bool check(vector<int>&a , long long k , long long x) {
        long long count = 0;
        for(int i : a) {
            count += i / x;
            if(count >= k) 
                return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = 0;
        for(int i : candies)
            sum += i;
        if(sum < k)
            return 0;
        long long left = 1 , right = *max_element(candies.begin(), candies.end()) , ans = 1;
        while(left <= right) {
            long long mid = (left + right) / 2;
            if(check(candies , k , mid)) {
                ans = mid;
                left = mid + 1;
            } else 
                right = mid - 1;
        }
        return ans;
    }
};