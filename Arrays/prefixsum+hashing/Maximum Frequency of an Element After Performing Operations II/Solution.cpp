// Problem Link : https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> freq;
        map<int, int> count;
        int maxi = *max_element(begin(nums), end(nums));
        for (auto it : nums) {
            freq[it]++;
            count[it - k] += 1;
            count[it + k + 1] -= 1;
            count[it] += 0;
        }
        int propagate = 0;
        int ans = 1;
        for (auto [num, sum] : count) {

            int inside_array = freq[num];
            int other = sum + propagate;

            int rem = inside_array + min(other - inside_array, numOperations);
            ans = max(ans, rem);
            propagate = other;
        }
        return ans;
    }
};
