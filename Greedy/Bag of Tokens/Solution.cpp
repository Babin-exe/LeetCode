// Problem Link : https://leetcode.com/problems/bag-of-tokens/description/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(begin(tokens), end(tokens));
        int i = 0, j = n - 1;
        int s = 0, ms = 0;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                s++;
                ms = max(ms, s);
                i++;
            } else if (s >= 1) {
                power += tokens[j]; 
                j--;
                s--;
            }else break;
        }
        return ms;
    }
};
