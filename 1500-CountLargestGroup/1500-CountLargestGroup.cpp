// Last updated: 6/10/2026, 7:21:07 PM
class Solution {
private:
    int sum(int n) {
        if(n == 0) 
            return 0;
        return (n%10) + sum(n / 10);
    }
public:
    int countLargestGroup(int n) {
        int ans = 1;
        map<int , int> mp;
        for(int i=1 ; i<=n ; i++) {
            mp[sum(i)]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;  
        });
        
        for(int i=1 ; i<vec.size() ; i++) {
            if(vec[i].second != vec[i-1].second)
                break;
            ans++;
        }
        return ans;
    }
};