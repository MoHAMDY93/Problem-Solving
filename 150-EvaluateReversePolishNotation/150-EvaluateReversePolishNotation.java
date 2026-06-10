// Last updated: 6/10/2026, 7:26:22 PM
import java.util.*;
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(String a : tokens) {
            if(a.equals("+") || a.equals("-") || a.equals("*") || a.equals("/")) {
                int op2 = st.pop();
                int op1 = st.pop();
                int res = switch(a) {
                    case "+" -> op1 + op2;
                    case "-" -> op1 - op2;
                    case "*" -> op1 * op2;
                    case "/" -> op1 / op2;
                    default -> 0;
                };
                st.push(res);
                // System.
            } else {
                st.push(Integer.parseInt(a));
            }
        }
        // System.out.println(st.size());
        return st.peek();
    }
}