// Problem Link : https://leetcode.com/problems/maximize-pair-strength-using-gcd/
using ll = long long;
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        ll ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll g = __gcd(nums[i], nums[j]);
                g *= g;
                if (g != 0)
                    ans = max(ans, (1LL*nums[i] * nums[j]) / g);
            }
        }
        return ans;
    }
};
