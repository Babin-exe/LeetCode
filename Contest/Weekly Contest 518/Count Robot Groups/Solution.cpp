// Problem Link : https://leetcode.com/problems/count-robot-groups/description/

class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int cp = n - 1;
        int c = 1;

        for (int i = n - 2; i >= 0;) {

            if (position[cp] - position[i] <= distance ||
                speed[i] > speed[cp] || position[i+1] - position[i] <=distance) {
                i--;
            } else {
                c++;
                cp = i;
                i--;
            }
        }
        return c;
    }
};
