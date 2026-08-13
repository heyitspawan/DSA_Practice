class Solution {
public:
string check(string a, string b){
    string res;
    int i=0;
    if(a==b) return a;
    while(a[i]==b[i]){
        res+=a[i];
        i++;
    }
    return res ;
}
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        return check(strs[0],strs[strs.size()-1]);
    }
};