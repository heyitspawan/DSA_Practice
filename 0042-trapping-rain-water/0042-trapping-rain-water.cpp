class Solution {
public:
    int trap(vector<int>& height) {
        int s=height.size();
        int h=height[0];
        int hr=height[s-1];
        vector<int>l(s,0);
        vector<int>r(s,0);
        int sum=0;
        for(int i=1;i<height.size();i++){
           if(h>height[i]){
            l[i]=h-height[i];
           }else{
            h=height[i];
           }
        }
        for(int i=s-2;i>=0;i--){
           if(hr>height[i]){
            r[i]=hr-height[i];
           }else{
            hr=height[i];
           }
        }
        for(int i=0;i<height.size();i++){
            sum+=min(l[i],r[i]);
        }
        return sum;
    }
};