class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> res;
        int c=0;
        vector<int> mp(10,0);
        for (int i = 0; i < digits.size(); i++) {
            mp[digits[i]]++;
        }
        for (int i = 1; i <= 9; i++){
            if(mp[i]==0){
                continue;
            }
            mp[i]--;
            for (int j = 0; j < 10; j++){
                if(mp[j]==0){
                continue;
            } 
            mp[j]--;
            for (int k = 0; k < 10; k=k+2){
                 if(mp[k]==0){
                continue;
            }
            mp[k]--;
            c++;
            int nums=100*i+10*j+k;
            res.push_back(nums);
            mp[k]++;
            }
            mp[j]++;
            }
            mp[i]++;
        }
        return c;
    }
};