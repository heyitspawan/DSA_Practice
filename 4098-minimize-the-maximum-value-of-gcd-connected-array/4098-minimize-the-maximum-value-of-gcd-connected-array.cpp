class Solution {
public:
    int smallfactor(int n) {
        for (int i = 2; i*i<=n; i++) {
            if (n % i == 0) {
                return i;
            }
        }
        return n;
    }
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) {
            return -1;
        }
        if (value % 2 == 0) {
            if ((value / 2) <= index) {
                return -1;
            } else {
                return (long long)value + (n - index-1) * 2;
            }
        } else {
                 int sf = smallfactor(value);
                int nvalue = value - sf;
            if (index != 0) {
              
                if (nvalue <= 1) {
                    return -1;//error
                }
                if ((nvalue / 2) <= (index-1)) {
                    return -1;
                }else if(index==n-1){
                    return value;
                }
                else {
                    return (long long)value+sf+ (n - index-2) * 2;
                }
            }else{
                 return (long long)value+sf+ (n - index-2) * 2;
            }
          
        }
        return -1;
    }
};