// Problem Link : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = INT_MIN, mini = INT_MAX, l = 0, r = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                l = i;
            }
            if (nums[i] < mini) {
                mini = nums[i];
                r = i;
            }
        }

        if (l > r)
            swap(l, r);

        return min({r + 1, n - l, l + 1 + n - r});
    }
};
