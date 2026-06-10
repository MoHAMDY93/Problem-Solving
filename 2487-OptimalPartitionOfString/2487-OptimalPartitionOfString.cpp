// Last updated: 6/10/2026, 7:16:48 PM
class Solution {
public:
    int partitionString(string s) {
        int n = s.length();

        vector<int> lastSeen(26,-1);

        int count = 0;
        int current = 0;

        for(int i =0;i<n;i++){
            char ch = s[i];

            if(lastSeen[ch-'a']>=current){
                count++;
                current = i;
            }

            lastSeen[ch-'a']=i;
        }

        return count+1;
    }
};