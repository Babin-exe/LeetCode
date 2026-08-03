// Problem Link : https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/description/
class Solution {
public:
    bool solve(vector<int>& m, vector<long long>& sum, long long ip) {
        long long mp = ip;
        for (int i = 0; i < m.size(); i++) {
            if (m[i] > mp + sum[i]) {
                return false;
            } else {
                mp -= m[i];
                if (mp < 0)
                    mp = 0;
            }
        }
        return true;
    }

    long long minInitialStrength(vector<int>& m, vector<vector<int>>& b) {
        int n = m.size();
        vector<long long> sum(n, 0);
        for (auto it : b) {

            int l = it[0];
            int r = it[1];
            int v = it[2];

            sum[l] += v;
            if (r + 1 < n)
                sum[r + 1] -= v;
        }
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i] + sum[i - 1];
        }
        long long l = 0, r = 50000000000000LL;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            if (solve(m, sum, mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};

