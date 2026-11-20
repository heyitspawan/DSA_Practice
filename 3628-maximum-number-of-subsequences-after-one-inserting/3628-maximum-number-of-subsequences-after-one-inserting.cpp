class Solution {
public:
    long long numOfSubsequences(string s) {
        string a;
        for (char ch : s) {
            if (ch == 'L' || ch == 'C' || ch == 'T') {
                a += ch;
            }
        }

        int n = a.size();
        if (n == 0) return 0;

        
        vector<long long> preL(n + 1, 0), preLC(n + 1, 0);
        vector<long long> sufT(n + 1, 0), sufCT(n + 1, 0);

        for (int i = 0; i < n; i++) {
            preL[i + 1] = preL[i] + (a[i] == 'L' ? 1 : 0);
            preLC[i + 1] = preLC[i] + (a[i] == 'C' ? preL[i] : 0);
        }

        for (int i = n - 1; i >= 0; i--) {
            sufT[i] = sufT[i + 1] + (a[i] == 'T' ? 1 : 0);
            sufCT[i] = sufCT[i + 1] + (a[i] == 'C' ? sufT[i + 1] : 0);
        }

        
        long long base = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 'C') {
                base += preL[i] * sufT[i + 1];
            }
        }

       
        long long maxGain = 0;
        for (int i = 0; i <= n; i++) {
            long long gainL = sufCT[i];          
            long long gainC = preL[i] * sufT[i];  
            long long gainT = preLC[i];          
            maxGain = max({maxGain, gainL, gainC, gainT});
        }

        return base + maxGain;
    }
};