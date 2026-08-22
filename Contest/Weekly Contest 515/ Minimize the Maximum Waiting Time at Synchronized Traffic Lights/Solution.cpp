// Problem Link : https://leetcode.com/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/description/
class Solution {
public:
    int minPenalty(int period, vector<int>& l, vector<int>& at) {
        sort(begin(l), end(l));
        int maxi = l[l.size() - 1];
        int ans = 0;

        for (int i = 0; i < at.size(); ++i) {
            int modi = at[i] % period;
            if (maxi <= modi) {r
                ans = max(ans, period - modi);
            }
        }
        return ans;
    }
};
