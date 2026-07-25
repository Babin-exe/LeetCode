// Problem Link : https://leetcode.com/problems/decode-xored-array/description/
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int n = encoded.size();
        for (int i = 0; i < n; i++) {
            first ^= encoded[i];
            ans.push_back(first);
        }
        return ans;
    }
};
