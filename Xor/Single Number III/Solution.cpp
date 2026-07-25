// Problem Link : https://leetcode.com/problems/single-number-iii/description/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for (auto& it : nums) {
            x ^= it;
        }

        int m = x & (-x);
        int a = 0, b = 0;

        for (auto& it : nums) {
            if (it & m) {
                a ^= it;
            } else
                b ^= it;
        }

        return {a, b};
    }
};
