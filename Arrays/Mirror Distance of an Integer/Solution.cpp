// Problem Link : https://leetcode.com/problems/mirror-distance-of-an-integer/description/
class Solution {
public:
    int mirrorDistance(int n) {
        if (n < 10)
            return 0;

        int t = 0;
        int x = n;
        while (x != 0) {
            t = (t * 10) + (x % 10);
            x /= 10;
        }
        return abs(n - t);
    }
};
