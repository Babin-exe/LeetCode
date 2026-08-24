// Problem Link : https://leetcode.com/problems/stone-game-viii/description/
class Solution {
public:
    int n;
    int dp[100001];
    int solve(vector<int>& p, int i) {
        if (i == n - 1) return p[n - 1];
        if (dp[i] != -1) return dp[i];
        int second = solve(p, i + 1);
        int first = p[i] - second;
        return dp[i] = max(first, second);
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> p(n, 0);
        memset(dp, -1, sizeof(dp));
        p[0] = stones[0];
        for (int i = 1; i < n; i++) p[i] = p[i - 1] + stones[i];
        return solve(p,1);
    }
};
