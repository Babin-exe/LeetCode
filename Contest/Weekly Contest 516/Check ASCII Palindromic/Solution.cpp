// Problem Link : https://leetcode.com/contest/weekly-contest-516/problems/check-ascii-palindromic/
class Solution {
public:
    bool isPalindromic(string s) {
        string t;
        for (char ch : s) {
            string tt;
            int num = ch - 0;
            int k = 128;

            while (k > 0) {
                if (num >= k) {
                    num -= k;
                    tt += '1';
                } else {
                    tt += '0';
                }
                k /= 2;
            }
            t += tt;
        }
        int sz = t.length();
        for (int i = 0; i < sz / 2; i++) {
            if (t[i] != t[sz - 1 - i])
                return false;
        }
        return true;
    }
};
