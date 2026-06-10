// Last updated: 6/10/2026, 7:21:58 PM
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int mn = Integer.MAX_VALUE;
        int n = arr.length;
        Arrays.sort(arr);
        for(int i=1 ; i<n ; i++) {
            mn = Math.min(mn , arr[i] - arr[i-1]);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=1 ; i<n ;i++){ 
            if(arr[i] - arr[i-1] == mn) ans.add(Arrays.asList(arr[i-1] , arr[i]));
        }
        return ans;
    }
}