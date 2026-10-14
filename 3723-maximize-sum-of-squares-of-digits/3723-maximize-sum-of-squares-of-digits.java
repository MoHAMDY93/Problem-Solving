class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) return "";         
        StringBuilder ans = new StringBuilder();
        while (sum > 0) {
            ans.append((char)(Math.min(sum , 9) + '0'));
            sum = Math.max(0 , sum - 9);
            num--;
        }
        while (num-- > 0) ans.append('0');
        return ans.toString(); 
    }
}