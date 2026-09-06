// Problem Link : https://leetcode.com/problems/distinct-subsequences/description/
class Solution {
public:
    int n;
    int dp[1001][1001];

    int solve(int i, int j, string c, string& s, string& t) {

        if (i == n) {
            return c == t;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int take = 0;
        if (s[i] == t[j]) {
            take = solve(i + 1, j + 1, c + s[i], s, t);
        }
        int ntake = solve(i + 1, j, c, s, t);

        return dp[i][j] = take + ntake;
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        n = s.length();
        return solve(0, 0, "", s, t);
    }
};
