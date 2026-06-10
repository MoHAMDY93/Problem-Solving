// Last updated: 6/10/2026, 7:18:29 PM
class Bank {
public:
    unordered_map<int , long long> acc;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size();
        for(int i=1 ; i<=n ; i++) {
            acc[i] = balance[i-1];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if((1 <= account1 && account1 <= n) && (1 <= account2 && account2 <= n)) {
            // cout << acc[account1] << ' ' << acc[account2] << '\n';
            if(acc[account1] >= money) {
                acc[account1] -= money;
                acc[account2] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(1 <= account && account <= n) {
            acc[account] += money;
            return true;
        }  
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(1 <= account && account <= n) {
            if(acc[account] >= money) {
                acc[account] -= money;
                return true;
            }
        }  
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */