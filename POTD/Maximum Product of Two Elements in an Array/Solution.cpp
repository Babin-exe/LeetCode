// Problem Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2026-07-27
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};
