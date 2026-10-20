class Solution {
public:
vector<int> a;
void computelps(vector<int>&pattern,vector<int>&lps){
    int m=pattern.size();
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];

            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}
bool kmpsearch(vector<int>&pattern,vector<int>&txt){
    int n=txt.size();
    int m=pattern.size();
    vector<int>lps(m,0);
    //vector<int>result;
    computelps(pattern,lps);
    int i=0;
    int j=0;
    while(i<n){
        if(pattern[j]==txt[i]){
            i++;
            j++;
        }
        if(j==m){
            return true;
        }else if(i<n&&pattern[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
    return false;
}
bool isrotate(vector<int>&p,vector<int>&q){
    vector<int>txt=q;
    txt.insert(txt.end(),q.begin(),q.end());
    return kmpsearch(p,txt);
}
bool sol(int k,vector<int>&nums){
    for(int i=0;i<nums.size();i+=k){
        vector<int>p(nums.begin()+i,nums.begin()+i+k);
         vector<int>q(a.begin()+i,a.begin()+i+k);
         if(!isrotate(p,q)){
            return false;
         }
    }
    return true;
}
    int sortableIntegers(vector<int>& nums) {
         a=nums;
        sort(a.begin(),a.end());
        int n=a.size();
        vector<int>b;
        int res=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                b.push_back(i);
            }
        }
        for(int i=0;i<b.size();i++){
           if( sol(b[i],nums)){
            res+=b[i];
           }
        }
        return res;
    }
};