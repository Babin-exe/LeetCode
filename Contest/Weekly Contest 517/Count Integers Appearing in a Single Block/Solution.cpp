// Problem Link : https://leetcode.com/problems/count-integers-appearing-in-a-single-block/description/
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        map<int, int> mp;
        for (auto it : nums)
            mp[it]++;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = mp[nums[i]];
            int t = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] != nums[i])
                    break;
                else
                    t++;
            }

            if (count == t)
                ans++;
        }
        return ans;
    }
};
