class Solution {
public:
    int search(vector<int>& nums, int target) {
        int curr = 0;
        int l = 0 , r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= nums[curr]) l = mid + 1;
            else curr = mid , r = mid-1;
        }
        auto it1 = lower_bound(nums.begin() , nums.begin() + curr,  target);
        auto it2 = lower_bound(nums.begin() + curr, nums.end() , target);
        // if (it1 != nums.end()) cout << *it1 << '\n';
        // if (it2 != nums.end()) cout << *it2 << '\n';
        if (it1 != nums.end() && *it1 == target) return it1 - nums.begin();
        if (it2 != nums.end() && *it2 == target) return it2 - nums.begin();
        return -1;
    }
};