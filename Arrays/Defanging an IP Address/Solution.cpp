// Problem Link : https://leetcode.com/problems/defanging-an-ip-address/description/
class Solution {
public:
    string defangIPaddr(string address) {

        string s;
        for (char ch : address) {
            if (ch != '.')
                s += ch;
            else {
                s += "[.]";
            }
        }
        return s;
    }
};
