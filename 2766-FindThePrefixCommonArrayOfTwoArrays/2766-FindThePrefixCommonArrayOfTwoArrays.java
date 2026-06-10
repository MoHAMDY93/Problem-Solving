// Last updated: 6/10/2026, 7:15:35 PM
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        Arrays.fill(ans , 0); 
        Set<Integer> st = new HashSet<>();
        for (int i=0 ; i<n ; i++) {
            if (st.contains(A[i])) ans[i]++;
            else st.add(A[i]);

            if (st.contains(B[i])) ans[i]++;
            else st.add(B[i]);
        }
        for (int i = 1 ; i<n ; i++) ans[i] += ans[i-1];
        return ans;
    }
}