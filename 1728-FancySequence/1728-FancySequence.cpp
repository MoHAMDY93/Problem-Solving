// Last updated: 6/10/2026, 7:20:16 PM
class Fancy {
private:    
    const long long MOD = 1e9 + 7;
    long long modInverse(long long x) {
        long long res = 1;
        long long e = MOD-2;
        while (e) {
            if (e & 1) res = res * x % MOD;
            x = x * x % MOD;
            e >>= 1;
        }
        return res;
    }
public:
    vector<long long> sq;
    long long add = 0 , mul = 1;
    Fancy() {
        
    }
    
    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = x * modInverse(mul) % MOD;
        sq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        add = add * m % MOD;
        mul = mul * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= sq.size()) return -1;
        return ((sq[idx] * mul % MOD) + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */