// Problem Link : https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01
class Solution {
public:
    int sum = 0;
    int n;
    int dp[21][21];

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
    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = nums.size();
        int l = 0, r = n - 1;
        for (auto& it : nums)
            sum += it;
        return solve(nums, l, r) >= 0;
    }
};
