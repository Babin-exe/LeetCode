// Problem Link : https://leetcode.com/problems/stone-game
class Solution {
public:
    int sum = 0;
    int n;
    int dp[501][501];

    int solve(vector<int>& nums, int l, int r) {
        if (l > r)
            return 0;
        if (l == r)
            return nums[l];

        if (dp[l][r] != -1)
            return dp[l][r];

        int a = nums[l] - solve(nums, l + 1, r);
        int b = nums[r] - solve(nums, l, r - 1);

        return dp[l][r] = max(a, b);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        return solve(piles, 0, n - 1) >= 0;
    }
};
