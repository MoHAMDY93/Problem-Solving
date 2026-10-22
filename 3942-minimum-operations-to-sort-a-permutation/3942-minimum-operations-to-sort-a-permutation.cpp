class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ind = find(nums.begin(), nums.end(), 0) - nums.begin();
        int n = nums.size();

        bool asc = true, desc = true;

        for(int i = 1; i < n; i++) {
            int next = nums[(ind + i) % n];

            if(next != i) asc = false;
            if(next != (n - i)) desc = false;
            if(!asc && !desc) return -1;
        }

        if(asc) {
            return min(ind, n - ind + 2);
        }
        
        if(desc) {
            return min(n - ind, ind + 2);
        }

        return -1;
    }
};