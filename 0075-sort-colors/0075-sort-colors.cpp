class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)a++;
            if(nums[i]==1)b++;
            if(nums[i]==2)c++;


            // for(int j=i+1;j<nums.size();j++){
            //     if(nums[i]>nums[j]){
            //         int t=nums[i];
            //         nums[i]=nums[j];
            //         nums[j]=t;
            //     }
            // }
        }int i=0;
        while(a--){
            nums[i]=0;
            i++;
         
        }
         while(b--){
            nums[i]=1;
            i++;
            
        } while(c--){
            nums[i]=2;
            i++;
          
        }
    }
};