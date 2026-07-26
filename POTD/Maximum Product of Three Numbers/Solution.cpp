// Problem Link : https://leetcode.com/problems/maximum-product-of-three-numbers/description/?envType=daily-question&envId=2026-07-26
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = -2000, b = -2000, c = -2000;
        int x = INT_MAX, y = INT_MAX, z = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > a) {
                c = b;
                b = a;
                a = nums[i];
            } else if (nums[i] > b) {
                c = b;
                b = nums[i];
            } else if (nums[i] > c) {

                c = nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] < x) {
                z = y;
                y = x;
                x = nums[i];
            } else if (nums[i] < y) {
                z = y;
                y = nums[i];
            } else {
                z = nums[i];
            }
        }

        return max({a * b * c, a * x * y, x * y * z});
    }
};
