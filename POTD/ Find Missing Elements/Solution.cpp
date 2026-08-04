// Problem Link : https://leetcode.com/problems/find-missing-elements/description/
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;
        sort(begin(nums), end(nums));
        for (int i : nums)
            st.insert(i);

        for (int i = nums[0]; i <= nums[nums.size() - 1]; i++) {
            if (!st.contains(i))
                ans.push_back(i);
        }
        return ans;
    }
};
