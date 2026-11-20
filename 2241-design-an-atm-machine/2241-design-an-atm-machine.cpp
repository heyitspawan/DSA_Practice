class ATM {
public:
    vector<int> notes;
    vector<int> count;
    ATM() {
        count.resize(5, 0);
        notes = {20, 50, 100, 200, 500};
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            count[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> c(5, 0);
        for (int i = 4; i >= 0; --i) {
            if (notes[i] <= amount) {
                int r = amount / notes[i];
                r = min(r, count[i]);
                c[i] = r;
                amount -= (notes[i] * r);
                count[i] -= r;
            }
        }
        if (amount != 0) {
            for (int i = 0; i < 5; i++) {
                count[i] += c[i];
            }
            return {-1};
        }
        return c;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */