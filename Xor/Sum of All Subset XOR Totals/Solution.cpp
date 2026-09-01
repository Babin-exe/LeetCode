// Problem Link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int t = 0;

        for (auto k : nums) {
            t |= k;
        }

        return t * (1 << (nums.size() - 1));
    }
};
