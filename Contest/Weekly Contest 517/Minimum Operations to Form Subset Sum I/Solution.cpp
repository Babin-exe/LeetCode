// Problem Link : https://leetcode.com/problems/minimum-operations-to-form-subset-sum-i/description/
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int inf = 1e9;
        vector<int> dp(sum + 1, inf);
        dp[0] = 0;

        for (auto x : nums) {
            long long t = x;
            int cost = 0;

            vector<int> ndp = dp;

            while (t <= sum) {

                for (int s = 0; s + t <= sum; s++) {
                    if (dp[s] == inf)
                        continue;
                    ndp[s + t] = min(ndp[s + t], dp[s] + cost);
                }
                cost++;
                t *= 2;
            }

            t = x / 2;
            cost = 1;
            while (t > 0) {
                for (int s = 0; s + t <= sum; s++) {
                    if (dp[s] == inf)
                        continue;
                    ndp[s + t] = min(ndp[s + t], dp[s] + cost);
                }
                t /= 2;
                cost++;
            }
            dp = ndp;
        }
        return dp[sum] == inf ? -1 : dp[sum];
    }
};
