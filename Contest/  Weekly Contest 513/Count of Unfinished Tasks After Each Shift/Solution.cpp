// Problem Link : https://leetcode.com/problems/count-of-unfinished-tasks-after-each-shift/description
using ll = long long;
class Solution {
public:
    int n;
    int bs(vector<ll>& s, ll t) {
        int l = 0, r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (s[mid] <= t)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {

        n = tasks.size();
        vector<ll> s(n, 0);
        s[0] = tasks[0];

        for (int i = 1; i < n; i++)
            s[i] = tasks[i] + s[i - 1];

        vector<int> ans;
        int m = shifts.size();

        ll t = 0;

        for (int i = 0; i < m; i++) {
            t += shifts[i];
            
            if (t >= s[n - 1]) {
                t = 0;
                ans.push_back(0);
            } else {
                int idx = bs(s, t);
                ans.push_back(n - idx);
            }
        }
        return ans;
    }
};
