// Problem Link : https://leetcode.com/contest/weekly-contest-516/problems/longest-subarray-with-at-most-k-distinct-prime-factors/description/

class Solution {
    static const int MAXN = 100000;
    static vector<int> spf;
    static vector<vector<int>> factors;
    static bool init;

    void precompute() {
        if (init)
            return;

        spf.resize(MAXN + 1);
        for (int i = 0; i <= MAXN; i++)
            spf[i] = i;

        for (int i = 2; i * i <= MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXN; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        factors.resize(MAXN + 1);
        for (int i = 2; i <= MAXN; i++) {
            int x = i;
            while (x > 1) {
                int prime = spf[x];
                factors[i].push_back(prime);
                while (x % prime == 0)
                    x /= prime;
            }
        }

        init = true;
    }

public:
    int longestSubarray(vector<int>& nums, int k) {
        precompute();

        int n = nums.size();
        int left = 0, dist = 0, ans = 0;

        vector<int> freq(MAXN + 1, 0);

        for (int right = 0; right < n; right++) {
            for (int it : factors[nums[right]]) {
                if (freq[it] == 0) {
                    dist++;
                }
                freq[it]++;
            }

            while (dist > k) {
                for (int it : factors[nums[left]]) {
                    freq[it]--;
                    if (freq[it] == 0) {
                        dist--;
                    }
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

vector<int> Solution::spf;
vector<vector<int>> Solution::factors;
bool Solution::init = false;
