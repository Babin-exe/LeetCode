// Problem Link : https://leetcode.com/problems/count-valid-prefixes/description/
class Solution {
public:
    int countValidPrefixes(string s) {
        int o = 0, z = 0, t = 0;
        for (auto& ch : s) {
            if (ch == '0') z++; 
            else o++;
            if(z == o || z==o+1 || o == z+1) t++;
        }
        return t;
    }
};
