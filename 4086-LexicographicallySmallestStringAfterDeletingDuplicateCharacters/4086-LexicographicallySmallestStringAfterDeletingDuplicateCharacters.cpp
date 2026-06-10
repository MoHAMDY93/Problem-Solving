// Last updated: 6/10/2026, 7:09:52 PM

class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int cnt[26]={};
        int n=s.size();
        for(char c:s){
            cnt[c-'a']++;
        }
        stack<char> st;
        while(!st.empty()){st.pop();}
        for(int i=0; i<n; i++){
            while(!st.empty()){
                char c=st.top();
                if(c<=s[i]){break;}
                if(cnt[c-'a']>1){
                    cnt[c-'a']--;
                    st.pop();
                }
                else{
                    break;
                }
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            char c=st.top();
            if(cnt[c-'a']>1){
                cnt[c-'a']--;
                st.pop();
            }
            else{
                break;
            }
        }
        string ans="";
        while(!st.empty()){
            char c=st.top();
            st.pop();
            ans.push_back(c);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};