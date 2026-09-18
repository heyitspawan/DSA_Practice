class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> start(26,-1);
        vector<int> end(26,-1);
        vector<bool> isvalid(26,true);
        vector<string> res;
        for(int i=0;i<n;i++){
            int ind=s[i]-'a';
            if(start[ind]==-1){
                start[ind]=i;
            }
            end[ind]=i;
        }

        for(int i=0;i<26;i++){
            if(start[i]==-1) continue;
            else {
                for(int j=start[i]+1;j<end[i];j++){
                    if(end[s[j]-'a']>end[i]){
                        end[i]=end[s[j]-'a'];
                    }
                    if(start[s[j]-'a']<start[i]){
                        isvalid[i]=false;
                    }
                }
            }
        }
        int laststart=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int c=s[i]-'a';
            if(isvalid[c]==false){
                continue;
            }
            if(start[c]==i && end[c]<laststart){
                res.push_back(s.substr(i,end[c]-i+1));
                laststart=i;
            }
        }
        return res;
    }
};