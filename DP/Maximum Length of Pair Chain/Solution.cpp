// Problem Link : https://leetcode.com/problems/maximum-length-of-pair-chain/

//Recursion + memo
class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(int idx, int prev, vector<vector<int>>& pairs) {

        if (idx == n) {
            return 0;
        }

        if (prev != -1) {
            if (dp[idx][prev] != -1)
                return dp[idx][prev];
        }

        int prevl = prev == -1 ? INT_MIN : pairs[prev][0];
        int prevr = prev == -1 ? INT_MIN : pairs[prev][1];

        int take = 0;

        if (prevr < pairs[idx][0]) {

            take = 1 + solve(idx + 1, idx, pairs);
        }

        int ntake = solve(idx + 1, prev, pairs);

        if (prev != -1) {

            return dp[idx][prev] = max(take, ntake);
        }
        return max(take, ntake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        sort(begin(pairs), end(pairs));
        n = pairs.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, pairs);
    }
};

// Greedy O(n logn))
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(begin(pairs), end(pairs));
        int n = pairs.size();

        vector<vector<int>> t;
        t.push_back(pairs[0]);

        for (int i = 1; i < n; i++) {
            int l = pairs[i][0];
            int r = pairs[i][1];

            if (l > t.back()[1]) {
                t.push_back({l, r});
            } else if (r < t.back()[1]) {
                t.back() = {l, r};
            }
        }

        return t.size();
    }
};
