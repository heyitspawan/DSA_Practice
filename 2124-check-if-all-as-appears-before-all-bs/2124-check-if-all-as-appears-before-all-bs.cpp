class Solution {
public:
    bool checkString(string s) {
        string a=s;
        sort(a.begin(),a.end());
        if(a==s){
            return true;
        }
        return false;
    }
};