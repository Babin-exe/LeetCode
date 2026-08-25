// Problem Link : https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = 100000;
        int n = nums.size();
        vector<int> f(maxi + 1, 0);
        vector<int> c(2 * maxi + 1, 0);

        for (auto it : nums) {
            f[it]++;
            int l = max(it - k, 0);
            int r = it + k;
            c[l] += 1;
            if (r + 1 < 2 * maxi + 1) {
                c[r + 1] -= 1;
            }
        }
        for (int i = 1; i < 2 * maxi + 1; i++) {
            c[i] += c[i - 1];
        }

        int ans = 0;
        for (int i = 0; i < 2 * maxi + 1; i++) {

            int possible = c[i];

            int already = 0;

            if (i < maxi + 1) {
                already = f[i];
            }

            int rem = possible - already;
            int maxpossible = already + min(numOperations, rem);
            ans = max(ans, maxpossible);
        }
        return ans;
    }
};
