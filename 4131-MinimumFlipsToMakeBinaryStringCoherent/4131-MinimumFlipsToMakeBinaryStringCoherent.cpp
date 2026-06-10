// Last updated: 6/10/2026, 7:09:07 PM
class Solution {
public:
    int minFlips(string s) {
        int os=0;
        int zs=0;
        int n=s.size();
        for(char ch:s){
            if(ch=='1')os++;
            else zs++;
        }
        if(os==0 || zs==0)return 0;
        if(os==1)return 0;
        int ans=os;
        if(os==2){
            if(s[0]=='1' && s[n-1]=='1')return 0;
            else return 1;
        }
        if(s[0]=='1' && s[n-1]=='1')ans-=2;
        else if(s[0]=='1' || s[n-1]=='1')ans-=1;
        else ans=ans-1;
        return min(ans,zs);
    }
};