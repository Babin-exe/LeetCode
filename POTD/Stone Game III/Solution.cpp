// Problem Link : https://leetcode.com/problems/stone-game-iii/description/
class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int>& s, int i) {
        if (i >= n)return 0;
        if (dp[i] != -1) return dp[i];
        int r = INT_MIN;
        r = max(r, s[i] - solve(s, i + 1));
        if (i + 1 < n)r = max(r, s[i] + s[i + 1] - solve(s, i + 2));
        if (i + 2 < n)r = max(r, s[i] + s[i + 1] + s[i + 2] - solve(s, i + 3));
        return dp[i] = r;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n + 1, -1);
        int a = solve(stoneValue, 0);
        return (a == 0 ? "Tie" : (a > 0 ? "Alice" : "Bob"));
    }
};
