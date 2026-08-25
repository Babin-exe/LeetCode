// Probelm Link : https://leetcode.com/problems/smallest-missing-multiple-of-k/description/?envType=daily-question&envId=2026-08-25
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> fq(101, 0);
        for (auto it : nums)
            fq[it]++;
        for (int i = 1; i <= 100; ++i) {
            if (fq[i] == 0 && i % k == 0)
                return i;
        }
        for (int i = 101;; i++) {
            if(i%k==0)return i;
        }
        return -1;
    }
};
