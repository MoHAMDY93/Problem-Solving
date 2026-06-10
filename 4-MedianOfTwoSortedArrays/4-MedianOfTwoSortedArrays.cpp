// Last updated: 6/10/2026, 7:28:26 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        vector<int>c(n + m);
    
        int i = 0 , j = 0 , k = 0;
        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                c[k++] = nums1[i++];
            }
            else if(nums1[i] > nums2[j]) {
                c[k++] = nums2[j++];
            }
            else {
                c[k++] = nums1[i++] , c[k++] = nums2[j++];
            }
        }

        if(i < n) {
            for( ; i < n ; ) 
                c[k++] = nums1[i++];
        }
        else if(j < m) {
            for( ; j < m ; )
                c[k++] = nums2[j++];
        }

        // for(int i=0 ; i<n+m ; i++) {
        //     cout<<c[i]<<' ';
        // }

        double ans;
        if((n+m) & 1)
            ans = double(c[(n+m) / 2.0]); 
        else 
            ans =  double((c[(n+m) / 2] + c[((n+m) / 2 - 1)])) / 2.0;
        
        return ans;
    }
};