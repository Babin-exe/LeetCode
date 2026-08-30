// Problem Link : https://leetcode.com/problems/sum-of-decoded-numbers/
using ll = long long;
class Solution {
public:
    long long modPow(long long x, long long y, long long mod) {
        ll ans = 1;
        while (y > 0) {
            if (y & 1)
                ans = (ans * x) % mod;

            x = (x * x) % mod;
             y>>=1;
        }
        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        const ll mod = 1e9 + 7;
        ll ans = 0;
        for (auto it : nums) {
            ll width = it % 10;
            ll d = it / 10;

            string s = to_string(d);
            ll x = stoll(s.substr(0, width));
            ll y = stoll(s.substr(width));

            ans = (ans % mod + modPow(x, y, mod) % mod) % mod;
        }
        return ans;
    }
};
