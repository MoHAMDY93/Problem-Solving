// Last updated: 6/10/2026, 7:23:40 PM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size() , ans = 0 , cnt = 0;
        sort(answers.begin() , answers.end());
        unordered_map<int , int>mp;
        for(int i=0 ; i<n ; i++) {
            if(answers[i] == 0) {
                cnt++;
                continue;
            }
            if(mp.find(answers[i]) == mp.end()) {
                ans += answers[i];
                cnt++;
                mp[answers[i]]++; 
            } else if(mp[answers[i]] == answers[i]) {
                mp.erase(answers[i]);
            }
            else 
                mp[answers[i]]++;
        }
        return ans + cnt;     
    }
};