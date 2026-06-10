// Last updated: 6/10/2026, 7:13:12 PM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for (int x : nums) {
            int sum = 0;
            for ( ; x ; x /= 10) sum += x % 10;
            mn = min(mn , sum);
        }
        return mn;
    }
};