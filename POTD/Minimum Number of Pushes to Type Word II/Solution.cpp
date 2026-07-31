// Problem Link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2026-07-31
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> ch(26, 0);
        for (auto c : word)
            ch[c - 'a']++;
        sort(begin(ch), end(ch), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int f = ch[i];
            ans += f * (i / 8 + 1);
        }
        return ans;
    }
};
