// Problem Link : https://leetcode.com/problems/house-robber/description/
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n, -1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

//Constant space : 
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        int two_step_back = 0, one_step_back = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int take = nums[i] + two_step_back;
            int ntake = one_step_back;
            ans = max(take, ntake);

            two_step_back = one_step_back;
            one_step_back = ans;
        }

        return ans;
    }
};
