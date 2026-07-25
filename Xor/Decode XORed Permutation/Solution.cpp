// Problem Link : https://leetcode.com/problems/decode-xored-permutation/description/
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {

        int n = encoded.size();
        int x = 0;
        for (int i = 1; i <= n + 1; i++)
            x ^= i;
        for (int i = 0; i < n; i += 2)
            x ^= encoded[i];
        vector<int> ans;
        ans.push_back(x);
        for (int i = n - 1; i >= 0; i--) {
            x = x ^ encoded[i];
            ans.push_back(x);
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};
