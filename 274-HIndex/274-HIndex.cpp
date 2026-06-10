// Last updated: 6/10/2026, 7:25:22 PM
class Solution {
private:
    bool check(int h , vector<int>& citations) {
        int cnt = 0;
        for(int i : citations) {
            if(i >= h)
                cnt++;
            if(cnt == h)
                return true;
        }
        return false;
    }
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(rbegin(citations) , rend(citations));
        int ans = 0;
        for(int h=1 ; h<=n ; h++) {
            if(!check(h , citations))
                break;
            ans = h;
        }
        return ans;
    }
};