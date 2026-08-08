// Problem Link : https://leetcode.com/problems/build-array-from-permutation/description/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> t(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            t[i] = nums[nums[i]];
        }
        return t;
    }
};
