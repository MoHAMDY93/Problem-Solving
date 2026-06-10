// Last updated: 6/10/2026, 7:14:28 PM
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); hFences.push_back(m);
        vFences.push_back(1); vFences.push_back(n);
        sort(hFences.begin() , hFences.end());
        sort(vFences.begin() , vFences.end());
        unordered_set<int> a;
        for(int i=0 ; i<hFences.size() ; i++) {
            for(int j=i+1 ; j < hFences.size() ; j++) {
                a.insert(hFences[j] - hFences[i]);
            }
        }
        long long ans = -1;
        for(int i=0 ; i<vFences.size() ; i++) {
            for(int j=i+1 ; j < vFences.size() ; j++) {
                if(a.count(vFences[j] - vFences[i])) {
                    long long side = vFences[j] - vFences[i];
                    ans = max(ans , side);
                }
            }
        }
        if(ans == -1) return ans;
        return (ans*ans) % ((long long)(1e9+7));
    }
};