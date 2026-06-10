// Last updated: 6/10/2026, 7:24:11 PM
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        sort(begin(cards) , end(cards));
        char ops[] = {'+' , '-' , '*' , '/'};
        const double EPS = 1e-6;
        auto apply = [&](double x , double y , char op , bool &ok) -> double {
            ok = true;
            if (op == '+') return x + y;
            if (op == '-') return x - y;
            if (op == '*') return x * y;
            if (op == '/') {
                if (fabs(y) < EPS) {ok = false; return 0;}
                return x / y;
            }
            ok = false; return 0;
        };
        do {
            for (char op1 : ops) {
                for (char op2 : ops) {
                    for (char op3 : ops) {
                        double a = cards[0] , b = cards[1] , c = cards[2] , d = cards[3];
                        bool ok;
                        double t1 , t2 , t3;
                        // form1: ((a op1 b) op2 c) op3 d
                        t1 = apply(a , b , op1 , ok);
                        if (ok) {
                            t2 = apply(t1 , c , op2 , ok);
                            if (ok) {
                                t3 = apply(t2 , d , op3 , ok);
                                if (ok && fabs(t3 - 24) < EPS) return true;
                            }
                        }
                        // form2: (a op1 (b op2 c)) op3 d
                        t1 = apply(b , c , op2 , ok);
                        if (ok) {
                            t2 = apply(a , t1 , op1 , ok);
                            if (ok) {
                                t3 = apply(t2 , d , op3 , ok);
                                if (ok && fabs(t3 - 24) < EPS) return true;
                            }
                        }
                        // form3: a op1 ((b op2 c)) op3 d)
                        t1 = apply(b , c , op2 , ok);
                        if (ok) {
                            t2 = apply(t1 , d , op3 , ok);
                            if (ok) {
                                t3 = apply(a , t2 , op1 , ok);
                                if (ok && fabs(t3 - 24) < EPS) return true;
                            }
                        }
                        // form4: a op1 (b op2 (c op3 d))
                        t1 = apply(c , d , op3 , ok);
                        if (ok) {
                            t2 = apply(b , t1 , op2 , ok);
                            if (ok) {
                                t3 = apply(a , t2 , op1 , ok);
                                if (ok && fabs(t3 - 24) < EPS) return true;
                            }
                        }
                        // form5: (a op1 b) op2 (c op3 d)
                        t1 = apply(a , b , op1 , ok);
                        if (ok) {
                            t2 = apply(c , d , op3 , ok);
                            if (ok) {
                                t3 = apply(t1 , t2 , op2 , ok);
                                if (ok && fabs(t3 - 24) < EPS) return true;
                            }
                        }
                    }
                }
            }
        } while(next_permutation(begin(cards) , end(cards)));
        return false;
    }
};