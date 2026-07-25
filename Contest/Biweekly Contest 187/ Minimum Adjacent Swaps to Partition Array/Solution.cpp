// Problem Link : https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/
using ll = long long;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        ll n = nums.size();
        ll t = 0;
        const int mod = 1e9 + 7;

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < a) {
                ans += (i - t);
                t++;
            }
        }
        ans %= mod;

        t = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < a)
                t--;
            else if (nums[i] > b) {
                ans += (t - i);
                t--;
            }
        }
        return ans % mod;
    }
};
