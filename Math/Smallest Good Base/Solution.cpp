// Problem Link : https://leetcode.com/problems/smallest-good-base/description/
using ull = unsigned long long;
class Solution {
public:
    string smallestGoodBase(string n) {
        ull num = stoull(n);
        // How many terms are we going to use 1 + base ^ 1 + base ^ 2 + ... base
        // ^ terms
        for (auto terms = 59; terms >= 1; --terms) {

            ull low = 2;
            ull high = pow(num, 1.0 / terms) + 1;

            while (low <= high) {

                ull mid = low + (high - low) / 2;

                __int128 sum = 1;
                __int128 value = 1;

                for (auto a = 1; a <= terms; ++a) {
                    value *= mid;
                    sum += value;
                    if (sum > num)
                        break;
                }

                if (sum == num) return to_string(mid);

                 if (sum < num)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return to_string(num-1);
    }
};
