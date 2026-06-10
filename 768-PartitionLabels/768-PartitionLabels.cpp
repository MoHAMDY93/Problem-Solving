// Last updated: 6/10/2026, 7:23:45 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastOcc[26] = {0};
        for(int i=0 ; i<s.length() ; i++) {
            lastOcc[s[i] - 'a'] = max(lastOcc[s[i] - 'a'] , i);
        }
        vector<int>ans; 
        int curr = lastOcc[s[0] - 'a'] , prev = 0;
        for(int i=1 ; i<s.length() ; i++) {
            if(i <= curr)
                curr = max(curr , lastOcc[s[i] - 'a']);
            else {
                ans.push_back(curr - prev + 1);
                prev = curr + 1;
                curr = lastOcc[s[i] - 'a'];
            }
        }
        ans.push_back(curr - prev + 1);
        return ans;
    }
};