class Solution {
    public String maskPII(String s) {
        s = s.toLowerCase();
        StringBuilder ans = new StringBuilder();
        if ('a' <= s.charAt(0) && s.charAt(0) <= 'z') {
            int at = s.indexOf('@');
            char fst = s.charAt(0) , lst = s.charAt(at - 1);
            ans.append(fst);
            ans.append("*****");
            ans.append(lst);
            ans.append(s.substring(at));
        } else {
            StringBuilder num = new StringBuilder();
            for (var c : s.toCharArray()) {
                if ('0' <= c && c <= '9') num.append(c);
            }
            // System.out.println(num.toString());
            int code = num.length() - 10;
            if (code > 0) {
                ans.append('+');
                for (int i=0 ; i<code ; i++) ans.append('*');
                ans.append('-');
            }
            System.out.println(code);
            for (int i=0 ; i<6 ; i++) {
                ans.append('*');
                if ((i+1) % 3 == 0) ans.append('-');
            }
            for (int i = code + 6 ; i<num.length() ; i++) {
                ans.append(num.charAt(i));
            }
        }
        return ans.toString();
    }
}