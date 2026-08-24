// Problem Link : https://leetcode.com/problems/shifting-letters-ii/description/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> sh(n, 0);

        for (vector<int> v : shifts) {
            int l = v[0];
            int r = v[1];
            int ops = v[2];

            if (ops == 0) {
                sh[l] -= 1;
                if (r + 1 < n)
                    sh[r + 1] += 1;
            } else {
                sh[l] += 1;
                if (r + 1 < n)
                    sh[r + 1] -= 1;
            }
        }

        for (int i = 1; i < n; i++)
            sh[i] += sh[i - 1];

        string ans;
        for (int i = 0; i < n; i++) {

            int pos = s[i] - 'a';
            ans += ('a' + ((pos + sh[i] % 26) + 26) % 26);
        }
        return ans;
    }
};
