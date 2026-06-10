// Last updated: 6/10/2026, 7:18:41 PM
class Solution {
public:
    int finalValueAfterOperations(vector<string>& ops) {
        int ans = 0;
        for(auto s : ops) {
            if(s == "X++" || s == "++X") ans++;
            else ans--;
        }
        return ans;
    }
};