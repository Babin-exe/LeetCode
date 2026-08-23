// Problem Link : https://leetcode.com/contest/weekly-contest-516/problems/find-all-numbers-disappeared-in-an-array-ii/
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {

        set<int> st;
        vector<vector<int>>ans;
        for (auto it : nums) {
            st.insert(it);
        }

        int l = lower;

        while (l <= upper) {
            if (st.count(l)) {
                l++;
                continue;
            }

            int start = l;
            while (l <= upper && !st.count(l)) {
                l++;
            }

            ans.push_back({start,l-1});

        }
        return ans;
    }
};
