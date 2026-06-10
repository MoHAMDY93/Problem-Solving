// Last updated: 6/10/2026, 7:19:44 PM
class Solution {
public:
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i=0 ; i<n ; i++) {
            make_set(i);
        }
        for (auto sw : allowedSwaps) {
            union_sets(sw[0] , sw[1]);
        }
        unordered_map<int , unordered_multiset<int>> mp;
        for (int i=0 ; i<n ; i++) {
            mp[find_set(i)].insert(source[i]);
        }
        int cnt = 0;
        for (int i=0 ; i<n ; i++) {
            auto& st = mp[find_set(i)]; 
            if (!st.count(target[i])) cnt++;
            else st.erase(st.find(target[i]));
        }
        return cnt;
    }
};