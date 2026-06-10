// Last updated: 6/10/2026, 7:17:24 PM
class Solution {
    public String removeDigit(String number, char digit) {
        List<Integer> idxs = new ArrayList<>();
        // int idx = -1;
        for (int i = 0; i < number.length(); i++) {
            if (number.charAt(i) == digit) {
                idxs.add(i);
                // break;
            }
        }
        if (idxs.isEmpty()) return number; // digit not found
        String res = "";
        for (var idx : idxs) {
            String temp = number.substring(0, idx) + number.substring(idx + 1);
            res = res.compareTo(temp) > 0 ? res : temp;
        }
        return res;
    }
}