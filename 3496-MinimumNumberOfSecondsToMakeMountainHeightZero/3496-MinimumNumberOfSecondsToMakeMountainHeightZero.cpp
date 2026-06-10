// Last updated: 6/10/2026, 7:13:24 PM
class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& wt) {
        int n = wt.size();
        vector<long long> cnt(n , 1);
        vector<long long> time(n , 0);
        priority_queue<pair<long long , long long> , vector<pair<long long , long long>> , greater<pair<long long , long long>>> pq;
        for (long long i=0 ; i<n ; i++) pq.push({wt[i] , i});
        while (h--) {
            auto [finish , idx] = pq.top();
            // cout << val << ' ' << time[idx] << '\n';
            pq.pop();
            time[idx] = finish;
            ++cnt[idx];
            pq.push({time[idx] + wt[idx] * cnt[idx] , idx});
        }
        return *max_element(time.begin() , time.end());
    }
};