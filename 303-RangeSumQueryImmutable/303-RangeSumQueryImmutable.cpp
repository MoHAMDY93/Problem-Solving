// Last updated: 6/10/2026, 7:25:18 PM
class NumArray {
public:
    vector<int>PS;
    NumArray(vector<int>& nums) {
        PS.push_back(0);
        for(int i : nums) {
            PS.push_back(PS.back() + i);
        }
    }
    
    int sumRange(int left, int right) {
        return PS[right+1] - PS[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */