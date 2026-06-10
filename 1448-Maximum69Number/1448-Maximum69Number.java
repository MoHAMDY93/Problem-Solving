// Last updated: 6/10/2026, 7:21:22 PM
class Solution {
    public int maximum69Number (int num) {
        String n = String.valueOf(num);
        char[] arr = n.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == '6') {
                arr[i] = '9';
                break;
            }
        }
        int res = Integer.parseInt(new String(arr));
        return res;
    }
}