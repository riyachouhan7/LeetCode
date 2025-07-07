class Bank {
public:
    vector<long long> totalBalance;
    Bank(vector<long long>& balance) {
        totalBalance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > totalBalance.size() || account2 > totalBalance.size()) return 0;
        if(totalBalance[account1 - 1] < money) return 0;

        totalBalance[account1 - 1] -= money;
        totalBalance[account2 - 1] += money;
        return 1;
    }
    
    bool deposit(int account, long long money) {
        if(account > totalBalance.size()) return 0;
        totalBalance[account - 1] += money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        if(account > totalBalance.size() || totalBalance[account -1] < money) return 0;
        totalBalance[account - 1] -= money;
        return 1;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */