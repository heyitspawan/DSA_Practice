class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // 'compID' assigns a group number to each index
        vector<int> compID(n);
        int currentGroup = 0;
        
        // Traverse the array once. If the jump between neighbors is > maxDiff,
        // it signifies a break in the path, so we start a new component.
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentGroup++;
            }
            compID[i] = currentGroup;
        }
        
        // Answer each query in O(1) time
        vector<bool> res;
        res.reserve(queries.size());
        for (const auto& q : queries) {
            // Path exists if both nodes are in the same component
            res.push_back(compID[q[0]] == compID[q[1]]);
        }
        
        return res;
    }
};// class Solution {
// public:
// void f(int i,vector<vector<int>>&adj, vector<bool>& visited,set<int>& r,queue<int>& q){
//     queue<int>p;
//     while(!q.empty()){
//         int i=q.front();
//         q.pop();
//        r.insert(i);
//        for(auto x:adj[i]){
//         if(!visited[x]){
//          visited[x]=true;
//          q.push(x);
//         }
        
//        }
//     }
// }
//     vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
//          int s=queries.size();
//         vector<bool>res(s,false);
//         vector<vector<int>>adj;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//              if(abs(nums[i]-nums[j])<=maxDiff){
//                 adj[i].push_back(j);
//                  adj[j].push_back(i);
//              }else{
//                 break;
//              }
//             }
//         }
//        int a,b;
//        vector<set<int>>com;
//        vector<bool>visited(n,false);
//        for(int i=0;i<n;i++){
//         if(!visited[i]){
//             visited[i]=true;
//             queue<int>q;
//             q.push(i);
//             set<int>r;
//           f(i,adj,visited,r,q);
//           com.push_back(r);
//         }
//        }
//        for(int i=0;i<s;i++){
//          a=queries[i][0];
//          b=queries[i][1];
//          for(int j=0;j<com.size();j++){
//             if(com[i].contains(a)&&com[i].contains(b)){
//                 res[i]=true;
//                 break;
//             }
//          }
//        }
       
//         return res;
//     }
// };
//  // for(int i=0;i<s;i++){
//         //     if(queries[i][0]<=queries[i][1]){
//         //          a=queries[i][0];
//         //          b=queries[i][1];
//         //     }else{
//         //          b=queries[i][0];
//         //          a=queries[i][1];
//         //     }
//         //     int k=a;
//         //     while(k!=b){
//         //      if(abs(nums[k]-nums[k+1])>maxDiff){
//         //         res[i]=false;
//         //         break;
//         //        }
//         //     k++;
//         //     }
            
//         // }