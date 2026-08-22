// Problem Link : https://leetcode.com/problems/maximum-gap-between-stations/description/
class Solution {
public:
    int maximumGap(string skill, string station) {
        vector<int> front;
        int t = 0;

        int n = station.length();

        for (int i = 0; i < n; i++) {
            if (t == skill.size())
                break;

            if (skill[t] == station[i]) {
                t++;
                front.push_back(i);
            }
        }

        vector<int> back;
        int l = skill.size() - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (l >= 0 && skill[l] == station[i]) {
                l--;
                back.push_back(i);
            }
        }
        reverse(begin(back), end(back));

        int ans = 0;
        for (int i = 1; i < front.size(); i++) {
            ans = max(ans, front[i] - front[i - 1]);
        }

        for (int j = back.size() - 1; j >= 1; j--) {
            ans = max(ans, back[j] - front[j - 1]);
        }

        return ans;
    }
};
