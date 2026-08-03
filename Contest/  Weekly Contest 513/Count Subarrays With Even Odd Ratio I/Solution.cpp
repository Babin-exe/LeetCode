// Problem Link : https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        vector<pair<int, int>> count;
        int o = 0, e = 0;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                e++;
            else
                o++;

            count.push_back({o, e});
        }

        for (int i = 0; i < n; i++) {
            int lo = 0, le = 0;
            if (i > 0) {
                lo = count[i - 1].first;
                le = count[i - 1].second;
            }

            for (int j = i; j < n; j++) {
                int ro = count[j].first;
                int re = count[j].second;

                int to = ro - lo;
                int te = re - le;

                if (to > 0 && te * b <= to * a) ans++;
            }
        }
        return ans;
    }
};
