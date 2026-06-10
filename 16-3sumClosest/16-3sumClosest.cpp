// Last updated: 6/10/2026, 7:28:07 PM
class Solution {
public:
    int threeSumClosest(vector<int>& a, int k) {   
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = 0, ref = INT32_MAX;
        for (int i = 0; i < n-2; i++) {
            int left = i+1, right = n-1;
            while (left < right) {
                int temp = a[i] + a[left] + a[right];
                if (temp <= k)
                    left++;
                else if (temp > k)
                    right--;
                if (abs(k - temp) < ref) {
                    ref = abs(k-temp);
                    ans = temp;
                }
                // cout<<temp<<' '<<ref<<endl;
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};