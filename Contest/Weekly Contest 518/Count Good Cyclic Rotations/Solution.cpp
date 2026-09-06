// Problem Link : https://leetcode.com/problems/count-good-cyclic-rotations/
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        int n = nums.size();
        vector<long long> ps(n);
        ps[0] = nums[0];

        for (int i = 1; i < n; i++) {
            ps[i] = nums[i] + ps[i - 1];
        }

        long long tot = ps[n - 1];
        int half = n / 2;

        int count = 0;

        for (int i = 0; i < n; i++) {

            long long right = i == 0 ? 0 : ps[i - 1];

            int t = half - i;

            if (t >= 0) {
                right += (tot - ps[n - 1 - t]);

            } else {
                right -= ps[abs(t) - 1];
            }

            if (right < (ps[n - 1] - right))
                count++;
        }
        return count;
    }
};
