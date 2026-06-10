// Last updated: 6/10/2026, 7:20:55 PM
import java.util.*;
class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<>();
        int curr = 0;
        for(int i=1 ; curr < target.length ; i++) {
            if(i == target[curr]) {
                ans.add("Push") ; 
                curr++;
            }
            else ans.addAll(Arrays.asList("Push" , "Pop"));
        }
        return ans;   
    }
}