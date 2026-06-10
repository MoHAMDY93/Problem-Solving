// Last updated: 6/10/2026, 7:16:59 PM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int MIN , cnt = 0 , r=0 , l=0;
        for(;r < k ; r++)
            cnt += (blocks[r] == 'W');
        
        MIN = cnt;
        
        // cout<<cnt<<endl;

        while(r < blocks.length()) {
            if(blocks[l] == 'W')
                cnt--;
            if(blocks[r] == 'W')
                cnt++;
            
            // cout<<cnt<<endl;
            
            MIN = min(cnt , MIN);
            l++; r++;
        }
        return MIN;
    }
};