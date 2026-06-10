// Last updated: 6/10/2026, 7:28:11 PM
class Solution {
public:
    int romanToInt(string s) {
        char a[] = {'I' , 'V' , 'X' , 'L' , 'C' , 'D' , 'M'};
        int b[] = {1 , 5 , 10 , 50 , 100 , 500 , 1000};
        vector<pair<char , int>>d(7);
        for(int i=0 ; i<7 ; i++){
            d[i].first=a[i];
            d[i].second=b[i];
        }
        long long ans=0;
        bool flag=true;
        for(int i=0 ; i<s.size() ; i++){
            int x=0 , y=0;flag = false;
            for(int j=0 ; j<7 ; j++){
                if(s[i]==d[j].first)x=d[j].second;
                if(s[i+1]==d[j].first)y=d[j].second;
            }
            if(x>=y){
                ans+=x;
                flag=true;
            }
            else{
                ans+=y-x;++i;
            }
    //        cout<<ans<<endl;
        }
    //    cout<<flag<<endl;
        // if(flag) {
        //     for (int j = 0; j < 7; j++)
        //         if (s.back() == d[j].first)ans += d[j].second;
        // }
        return ans;
    }
};