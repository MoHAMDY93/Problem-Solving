class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int , int>> vp;
        for (int i=0 ; i<n ; i++) vp.emplace_back(nums[i] , i);
        sort(begin(vp) , end(vp));
        vector<int> ids(n , -1);
        int l=0 , id = 0;
        for (int r=0 ; r<n ; r++) {
            if (vp[r].first <= vp[l].first + limit) ids[vp[r].second] = id , l = r;
            else id++ , ids[vp[r].second] = id , l = r;
        }
        // for (int i=0 ; i<n ; i++) {
        //     cout << ids[i] << ' ';
        // }
        // cout << '\n';
        priority_queue<int , vector<int> , greater<int>> pq[id+1];
        for (int i=0 ; i<n ; i++) pq[ids[i]].push(nums[i]);
        vector<int> ans;
        for (int i=0 ; i<n ; i++) { 
            ans.push_back(pq[ids[i]].top());
            pq[ids[i]].pop();
        }
        return ans;
    }
};