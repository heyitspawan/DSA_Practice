class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ints) {
        sort(ints.begin(),ints.end());
        vector<vector<int>> res={ints[0]};
        int j=0;
        for(int i=1;i<ints.size();i++){
           if(res[j][1]>=ints[i][0]){
        
          res[j][1]=max( res[j][1],ints[i][1]);
           }
           else{
            res.push_back(ints[i]);
            j++;
           }
        }return res;
    }
};