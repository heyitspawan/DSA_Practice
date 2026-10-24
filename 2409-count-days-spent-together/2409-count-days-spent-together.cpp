class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arr[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
         string a= max(arriveAlice,arriveBob);
         string b =min(leaveAlice,leaveBob);
         int res=0;
          if(b<a){
            return 0;
          }
         int am=stoi(a.substr(0,2));
         int ad=stoi(a.substr(3,2));
         int bm=stoi(b.substr(0,2));
         int bd=stoi(b.substr(3,2));
         if(bd<ad){
            bm--;
            bd+=arr[bm-1];
         }
         res+=bd-ad+1;
         int r=bm-am;
         for(int i=0;i<r;i++){
            res+=arr[am+i-1];
         }
         return res; 
    }
};