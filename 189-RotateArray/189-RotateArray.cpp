// Last updated: 6/10/2026, 7:26:00 PM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin() + n - k, nums.end()); // Reverese the last k elements
        reverse(nums.begin(), nums.begin() + n - k); // reverse the first n-k elements
        reverse(nums.begin(), nums.end()); // Reverse the whole array
    }
};