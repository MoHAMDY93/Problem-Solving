// Last updated: 6/10/2026, 7:09:56 PM
class Solution {
public:
    const int B = 300;
    vector<int> nums;
    int n;

    vector<unordered_map<int , long long>> freq;
    vector<long long> lazy;
    vector<int> block_id;
    void build(int b) {
        freq[b].clear();
        int L = b*B;
        int R = min(n-1 , (b+1) * B - 1);
        for (int i =L ; i<=R ; i++) {
            nums[i] += lazy[b];
            freq[b][nums[i]]++;
        }
        lazy[b] = 0;
    }
    void range_add(int l , int r , int val) {
        int bl = l / B;
        int br = r / B;
        for (int b = bl ; b<=br ; b++) {
            int ll = b * B , rr = min(n-1 , (b+1) * B - 1);
            if (l <= ll && rr <= r) lazy[b] += val;
            else {
                build(b);
                for (int i = max(ll , l) ; i<= min(rr , r) ; i++) {
                    freq[b][nums[i]]--;
                    nums[i] += val;
                    freq[b][nums[i]]++;
                }
            }
        }
    }
    long long count(int target) {
        long long res= 0 ;
        for (int b=0 ; b < (n + B - 1) / B ; b++) {
            // for (auto& p : freq[b]) {
            //     if (p.first + lazy[b] == target) {
            //         res += p.second;
            //     }
            // }
            long long req = target - lazy[b];
            if (freq[b].count(req)) res += freq[b][req];
        }
        return res;
    } 
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        nums = nums2;
        n = nums2.size();
        int blocks = (n + B - 1) / B;
        freq.assign(blocks , {});
        lazy.assign(blocks , 0);

        for (int b=0 ; b<blocks ; b++) build(b);
        vector<int> ans;
        for (auto q : queries) {
            if (q[0] == 1) range_add(q[1] , q[2] , q[3]);
            else {
                long long res = 0;
                for (int i : nums1) res += count(q[1] - i);
                ans.push_back(res);
            }
        }
        return ans;
    }
};