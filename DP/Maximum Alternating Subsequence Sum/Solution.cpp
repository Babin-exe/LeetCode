// Problem Link : https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/

//Recursion + Memoization :
using ll = long long;
class Solution {
public:
    int n;
    ll ans = 0;
    ll dp[100001][2];
    ll solve(int i, int sign, vector<int>& nums) {

        if (i == n) return 0;

        int id = (sign == 1) ? 1 : 0;

        if (dp[i][id] != -1) return dp[i][id];
        ll take = solve(i + 1, sign * -1, nums) + (nums[i] * sign);
        ll ntake = solve(i + 1, sign, nums);

        int idx = (sign == 1) ? 1 : 0;
        return dp[i][idx] = max(take, ntake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, nums);
    }
};
