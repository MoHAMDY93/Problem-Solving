// Last updated: 6/10/2026, 7:14:51 PM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        for(int i=0 ; i<n ; i++) {
            vector<string>temp = {words[i]};
            int cnt = 1 , prev = groups[i];
            for(int j=i+1 ; j<n ; j++) {
                if(groups[j] != prev) {
                    temp.push_back(words[j]);
                    cnt++ , prev = groups[j];
                }  
            }
            if(cnt > ans.size()) {
                ans = temp;
            }
        }
        return ans;   
    }
};