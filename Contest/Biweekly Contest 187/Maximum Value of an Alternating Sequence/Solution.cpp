// Problem Link : https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/description/
using ll = long long;
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
            return s;

        ll factor = n / 2;
        ll sub = 0;
        sub = factor - 1;

        return 0LL + s + 1LL * factor * m - sub;
    }
};
