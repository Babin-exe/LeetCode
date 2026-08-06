// Problem Link : https://leetcode.com/problems/smallest-divisible-digit-product-i
class Solution {
public:
    int dprod(int t) {
        int a = 1;
        while (t != 0) {
            a *= t % 10;
            if (a == 0)
                return 0;
            t /= 10;
        }
        return a;
    }
    int smallestNumber(int n, int t) {

        for (int i = n; i <= n + 10; i++) {
            int p = dprod(i);
            if (p % t == 0)
                return i;
        }
        return -1;
    }
};
