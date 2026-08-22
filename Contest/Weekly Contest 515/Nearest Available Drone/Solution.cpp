// Problem Link : https://leetcode.com/problems/nearest-available-drone/
 class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int ps = INT_MAX;
        for (int i = 0; i < drones.size(); i++) {
            int sum =
                abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);

            if (drones[i][2] >= sum && sum < ps) {
                ans = i;
                ps = sum;
            }
        }
        return ans;
    }
};
