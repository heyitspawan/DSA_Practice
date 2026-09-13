class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();          // number of rows
        int m = mat[0].size();       // number of columns

        // Binary search for the correct row
        int l = 0;
        int r = n - 1;
        int ind = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mat[mid][0] == t)
                return true;

            if (mat[mid][0] < t) {
                ind = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // Binary search inside the selected row
        l = 0;
        r = m - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mat[ind][mid] == t)
                return true;

            if (mat[ind][mid] < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};
