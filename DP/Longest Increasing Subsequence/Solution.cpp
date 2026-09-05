// Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/description/

//Simplified Bottom up ishh solution....
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
                    ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//Recursion + memo : 
class Solution {
public:
    int n;
    int dp[2501][2502];
    int solve(int i, int prev, vector<int>& nums) {
        if (i == n)
            return 0;

        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int pval = prev == -1 ? INT_MIN : nums[prev];
        int take = 0;

        if (nums[i] > pval) {
            take = 1 + solve(i + 1, i, nums);
        }

        int ntake = solve(i + 1, prev, nums);

        return dp[i][prev+1] = max(take, ntake);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};
