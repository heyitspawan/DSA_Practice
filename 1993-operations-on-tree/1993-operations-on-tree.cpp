class LockingTree {
public:
    int n;
    vector<int> lu;
    vector<int> pt;
    vector<vector<int>>adj;
    LockingTree(vector<int>& parent) {
        n = parent.size();
        pt = parent;
        lu.resize(n, -1);
        adj.resize(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lu[num] == -1) {
            lu[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (lu[num] == user) {
            lu[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {

        if (lu[num] == -1) {
            int i = pt[num];
            while (i != -1 && lu[i] == -1) {
                i = pt[i];
            }
            if (i != -1) {
                return false;
            }
            stack<int> st;
            for(int j:adj[num]){
                st.push(j);
            }
            int flag = 0;
            while (!st.empty()) {
                int j = st.top();
                st.pop();
                if (lu[j] != -1) {
                    flag = 1;
                    lu[j] = -1;
                }
                for(int k:adj[j]){
                st.push(k);
            }
               
            }
            if (flag == 0) {
                return false;
            }
            lu[num] = user;
            return true;
        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */