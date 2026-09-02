// Problem Link :https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int dp[100];
    int n;
    int ans = 0;

    int solve(int i, int end, vector<int>& nums) {
        if (i > end) {
            return ans;
        }

        if (dp[i] != -1)
            return dp[i];

        int take = solve(i + 2, end, nums) + nums[i];
        int ntake = solve(i + 1, end, nums);

        return dp[i] = max(take, ntake);
    }

    int rob(vector<int>& nums) {
        n = nums.size();

if(n==1) return nums[0];

        memset(dp, -1, sizeof(dp));

        int take_last = solve(0, n - 2, nums);

        memset(dp, -1, sizeof(dp));
        int take_second_last = solve(1,n-1,nums);

        return max(take_last,take_second_last);
    }
};
