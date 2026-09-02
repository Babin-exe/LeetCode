// Problem Link :https://leetcode.com/problems/house-robber-ii/

// Recursion + memo
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

//Bottom up Version : 
class Solution {
public:
    int dp[101];
    int n;
    int rob(vector<int>& nums) {
        n = nums.size();

        if(n==1) return nums[0];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n - 2; i++) {
            int take = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int ntake = i - 1 >= 0 ? dp[i - 1] : 0;
            dp[i] = max(take, ntake);
        }

        int case1 = dp[n - 2];

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n - 1; i++) {
            int take = nums[i] + (i - 2 >= 1 ? dp[i - 2] : 0);
            int ntake = i - 1 >= 1 ? dp[i - 1]:0;

            dp[i] = max(take,ntake);
        }

        int case2 = dp[n - 1];

        return max(case1, case2);
    }
};

