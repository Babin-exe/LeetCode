// Problem Link : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/
using ll = long long;
class Solution {
public:
    const int mod = 1e9 + 7;
    int n;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = ans * a % mod;

            a = a * a % mod;
            b /= 2;
        }

        return ans;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        if (m == 1)
            return nums;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            pq;
        n = nums.size();

        int maxi = -1;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
            maxi = max(maxi, nums[i]);
        }

        while (k > 0) {

            auto [mini, idx] = pq.top();
            pq.pop();

            ll multi = mini * m;
            pq.push({multi, idx});
            k--;

            if (multi > maxi)
                break;
        }

        ll divi = k / n;
        int modi = k % n;

        ll multiplier = power(1LL * m, divi);
        vector<pair<ll, int>> other;

        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            nums[idx] = (val % mod * multiplier % mod) % mod;
            other.push_back({val, idx});
        }

        for (int i = 0; i < n; i++) {
            pq.push(other[i]);
        }

        while (modi--) {
            auto [val, idx] = pq.top();
            pq.pop();

            ll t = m;
            nums[idx] = nums[idx] % mod * t % mod;
        }

        return nums;
    }
};
