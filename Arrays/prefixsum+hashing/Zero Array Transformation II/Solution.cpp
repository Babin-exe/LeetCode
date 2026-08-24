// Problem Link :https://leetcode.com/problems/zero-array-transformation-ii/description/
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size();
        int n = nums.size();
        int k = -1;

        vector<int> vt(n);

        while (l <= r) {
            fill(vt.begin(), vt.end(), 0);

            int mid = l + (r - l) / 2;

            for (int i = 0; i < mid; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2];

                vt[l] -= val;
                if (r + 1 < n)
                    vt[r + 1] += val;
            }

            bool good = true;
            int aval = 0;

            for (int i = 0; i < n; i++) {
                aval += vt[i];
                if (aval + nums[i] > 0) {
                    good = false;
                    break;
                }
            }

            if (good) {
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return k;
    }
};
