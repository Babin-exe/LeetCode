// Problem Link : https://leetcode.com/problems/increment-submatrices-by-one/description/
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> vt(n, vector<int>(n, 0));
        for (vector<int> v : queries) {
            int r1 = v[0];
            int c1 = v[1];
            int r2 = v[2];
            int c2 = v[3];
            for (int i = r1; i <= r2; i++) {
                vt[i][c1] += 1;
                if (c2 + 1 < n)
                    vt[i][c2 + 1] -= 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                vt[i][j] += vt[i][j - 1];
            }
        }
        return vt;
    }
};
