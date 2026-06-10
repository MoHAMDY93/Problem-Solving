// Last updated: 6/10/2026, 7:16:52 PM
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());
        priority_queue<long long , vector<long long> , greater<long long>> free;
        priority_queue<pair<long long , long long> , vector<pair<long long , long long>> , greater<pair<long long , long long>>> busy;
        for(long long i=0 ; i<n ; i++) free.push(i);
        map<long long , long long> mp;
        for(auto m : meetings) {
            long long start = m[0] , end = m[1];
            while(!busy.empty() && start >= busy.top().first) {
                auto [time , curr] = busy.top(); busy.pop();
                free.push(curr);
            }
            if(!free.empty()) {
                long long curr = free.top(); free.pop();
                busy.push({end , curr});
                mp[curr]++;
            } else {
                auto [time , curr] = busy.top(); busy.pop();
                busy.push({time + end - start , curr});
                mp[curr]++;
            }
        }
        long long ans = 0 , mx = 0;
        for(auto [f , s] : mp) {
            if(s > mx) mx = s , ans = f;
        }
        return ans;
    }
};