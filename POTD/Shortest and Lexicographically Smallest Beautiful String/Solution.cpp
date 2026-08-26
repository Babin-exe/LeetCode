// Problem Link : https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            int count = 0;
            string temp = "";
            for (int j = i; j < n; j++) {
                temp += s[j];
                if (s[j] == '1') {
                    count++;
                    if (count == k) {
                        if (ans == "" || temp.length() < ans.length() ||
                            (temp.length() == ans.length() && temp < ans)) {
                            ans = temp;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
