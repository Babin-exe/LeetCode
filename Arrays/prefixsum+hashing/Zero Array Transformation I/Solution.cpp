// Problem Link : https://leetcode.com/problems/zero-array-transformation-i/description/
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> vt(n + 1, 0);
        for (vector<int> v : queries) {
            int l = v[0];
            int r = v[1];

            vt[l] -= 1;
            vt[r + 1] += 1;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += vt[i];
            if (sum + nums[i] > 0) return false;
        }
        return true;
    }
};
