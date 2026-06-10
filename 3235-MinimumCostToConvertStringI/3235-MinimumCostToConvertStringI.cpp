// Last updated: 6/10/2026, 7:14:32 PM
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int , int>>> adj(26);
        int n = original.size();
        for(int i=0 ; i<n ; i++) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a' , cost[i]});
        } 
        function<long long(long long , long long)> dijkstra = [&](long long start , long long end) {
            priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;
            vector<long long> dist(26 , INT_MAX);
            pq.push({0 , start});
            dist[start] = 0;
            while(!pq.empty()) {
                auto [c , u] = pq.top(); pq.pop();
                if(c > dist[u]) continue;
                for(auto [v , w] : adj[u]) {
                    if(dist[v] > c + w) {
                        dist[v] = c + w;
                        pq.push({dist[v] , v});
                    }
                }
            }
            return dist[end];
        };
        // cout << dijkstra(2 , 1) << endl;
        long long ans = 0;
        map<pair<int , int> , long long> mp;
        int m = source.size();
        for(long long i=0 ; i<m ; i++) {
            auto p = make_pair(source[i] - 'a' , target[i] - 'a');
            if(mp.count(p)) ans += mp[p];
            else {
                long long c = dijkstra(source[i] - 'a' , target[i] - 'a');
                if(c == INT_MAX) return -1;
                mp[p] = c;
                ans += c;
            }
        }
        return ans;
    }
};