// Problem Link : https://leetcode.com/problems/frog-jump/description/
class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int dp[2001][2001];

    bool solve(vector<int>& stones, int idx, int prev) {
        if (idx == n - 1) return true;

        if (dp[idx][prev] != -1) return dp[idx][prev];

        bool t = false;
        for (int i = prev - 1; i <= prev + 1; i++) {
            if (i > 0) {
                int val = stones[idx] + i;
                if (mp.find(val) != mp.end()) {
                    t = t || solve(stones, mp[val], i);
                }
            }
        }

        return dp[idx][prev] = t;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        memset(dp, -1, sizeof(dp));
        if (stones[1] != 1) return false;
        for (int i = 0; i < n; i++) mp[stones[i]] = i;
        return solve(stones, 0, 0);
    }
};
