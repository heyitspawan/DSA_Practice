class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res;
        unordered_map<string, string> mp;
        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        int n=s.size();
        int c = 0;
        for (int i= 0; i < n; i++) {
            if (s[i] == '(') {
                string a;
                while (s[++i] != ')') {
                    a += s[i];
                }
                if(mp.find(a)!=mp.end()){
                   res+=mp[a]; 
                }else{
                    res+='?';
                }
                
            }else{
              res+=s[i];
            }
           
        }
        return res;
    }
};