// Last updated: 6/10/2026, 7:19:07 PM
class MovieRentingSystem {
public:
    map<int , set<pair<int , int>>> mp;
    set<array<int , 3>> st;
    map<pair<int , int> , int> kv;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        mp.clear();
        st.clear();
        for(auto v : entries) {
            mp[v[1]].insert({v[2] , v[0]});
            kv[{v[0] , v[1]}] = v[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ret;
        int cnt = 0;
        for(auto p : mp[movie]) {
            if(cnt == 5) break;
            if(st.count({p.first , p.second , movie})) continue;
            ret.push_back(p.second);
            cnt++;
        }
        return ret;
    }
    
    void rent(int shop, int movie) {
        st.insert({kv[{shop , movie}] , shop , movie});
    }
    
    void drop(int shop, int movie) {
        st.erase({kv[{shop , movie}] , shop , movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ret;
        int cnt = 0;
        for(auto a : st) {
            if(cnt == 5) break;
            ret.push_back({a[1] , a[2]});
            cnt++;
        }
        return ret;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */