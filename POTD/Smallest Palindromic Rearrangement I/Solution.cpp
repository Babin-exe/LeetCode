// Problem Link : https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/?envType=daily-question&envId=2026-07-28
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if (n == 1)
            return s;

        string st = s.substr(0, n / 2);
        vector<int> t(26, 0);
        for (int i = 0; i < st.length(); i++)
            t[st[i] - 'a']++;

        string ans;
        for (int i = 0; i < 26; i++) {
            int count = t[i];
            while (count--) {
                ans += (i + 'a');
            }
        }
        string other;
        if (n % 2 != 0)
            other += s[ceil(n / 2)];

        cout << "The value of ans is : " << ans << "\n";

        int k = ans.length() - 1;
        for (int i = k; i >= 0; i--) {
            other += ans[i];
        }

        return ans + other;
    }
};
