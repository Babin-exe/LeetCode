// Problem Link : https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/
class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        string t;
        int xc = 0, yc = 0;
        for (char ch : s) {
            if (ch == x)
                xc++;
            else if (ch == y)
                yc++;
            t.push_back(ch);
        }
        while (yc--)
            t.push_back(y);
        while (xc--)
            t.push_back(x);

        return t;
    }
};
