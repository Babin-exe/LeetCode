// Problem Link : https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/
class Solution {
public:
    int countRotations(string s, int k) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int count = 0;

            string t = s.substr(i) + s.substr(0, i);

            for (int j = 0; j < n - 1; j++) {
                if (t[j] == t[j + 1])
                    count++;
            }
            if (count == k)
                ans++;
        }
        return ans;
    }
};
