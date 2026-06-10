// Last updated: 6/10/2026, 7:11:51 PM
class Router {
public:
    set<array<int , 3>> st;
    deque<array<int , 3>> q;
    map<int , vector<int>> mp;
    map<int , int> cnt;
    int mx;
    Router(int memoryLimit) {
        q.clear();
        st.clear();
        mp.clear();
        mx = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto toAdd = array<int , 3>{source , destination , timestamp};
        if(st.count(toAdd)) return false;
        st.insert(toAdd) , q.push_back(toAdd), mp[destination].push_back(timestamp);
        if(q.size() > mx) {
            auto old = q.front();
            q.pop_front();
            st.erase(old);
            // mp[old[1]].erase(mp[old[1]].find(old[2]));
            cnt[old[1]]++;
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> toForward;
        if(q.empty()) return toForward;
        else {
            auto tmp = q.front();
            toForward.assign(tmp.begin() , tmp.end());
            q.pop_front();
            st.erase(tmp);
            cnt[tmp[1]]++;
            // mp[tmp[1]].erase(mp[tmp[1]].find(tmp[2]));
            return toForward;
        }
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(!mp.count(destination)) return 0;
        auto &v = mp[destination];
        auto it1 = lower_bound(begin(v)+cnt[destination] , end(v) , startTime);
        auto it2 = upper_bound(begin(v)+cnt[destination] , end(v) , endTime);
        // return distance(it1, it2);
        return it2 - it1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */