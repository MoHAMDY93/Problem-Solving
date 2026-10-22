class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        nums.reserve(n * 2);
        nums.insert(nums.end(), nums.begin(), nums.end());
        // for (auto i : nums) cout << i << ' ';
        // cout << '\n';
        for (int i = 2*n-1 ; i>0 ; i--) nums[i] = nums[i] - nums[i-1];
        // for (auto i : nums) cout << i << ' ';
        // cout << '\n';
        unordered_map<int , int> freq;
        for (int i=1 ; i<2*n ; i++) {
            if (i >= n) freq[nums[i - (n-1)]]--;
            freq[nums[i]]++;
            // cout << "i: " << i << '\n'; 
            // cout << "freq[+1]: " << freq[+1] << '\n'; 
            // cout << "freq[-1]: " << freq[-1] << '\n'; 
            if (freq[+1] == n-1) return min(i - (n-1) , (2*n-1) - i + 2);
            if (freq[-1] == n-1) return min(i - (n-1) , (2*n-1) - i) + 1;
        }
        return -1;
    }
};