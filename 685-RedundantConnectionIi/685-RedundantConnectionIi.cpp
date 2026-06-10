// Last updated: 6/10/2026, 7:24:02 PM
#include "bits/stdc++.h"
using namespace std;

class DSU {
private:
    vector<int> par , sz;
    int comps;
public:
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        par.resize(n);
        iota(par.begin() , par.end() , 0);
        sz.assign(n , 1);
        comps = n;
    }

    int find(int u) {
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }

    void unite(int a , int b) {
        if(!same(a , b)) {
            a = find(a);
            b = find(b);
            if(sz[a] > sz[b])
                swap(a , b);
            sz[b] += sz[a];
            par[a] = b;
            --comps;
        }
    }

    bool same(int a , int b) {
        return find(a) == find(b);
    }

    int size(int u) {
        return sz[find(u)];
    }

    int getComps() {
        return comps;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> cand1, cand2;
        // Step 1: check for two parents
        
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            if(parent[v] == 0) parent[v] = u;
            else {
                cand1 = {parent[v], v}; // first parent
                cand2 = e;              // second parent
                e[1] = 0;               // temporarily remove second edge
            }
        }
        
        // Step 2: detect cycle using DSU
        DSU dsu(n+1);
        for(auto &e : edges) {
            if(e[1] == 0) continue;
            int u = e[0], v = e[1];
            if(dsu.same(u, v)) {
                if(cand1.empty()) return e;
                else return cand1;
            }
            dsu.unite(u, v);
        }
        
        // Step 3: if no cycle, remove second edge
        return cand2;
    }
};