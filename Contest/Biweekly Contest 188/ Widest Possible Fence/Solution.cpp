// Problem Link : https://leetcode.com/problems/widest-possible-fence/description/

// Initial idea : O(n^3)
  
// class Solution {
// public:
//     int maximumWidth(vector<int>& planks) {
//         int n = planks.size();
//         sort(begin(planks), end(planks));
//         map<int, int> mp;
//         for (int i = 0; i < n; i++)
//             mp[planks[i]]++;
//         set<int> st;
//         int ans = 0;

//         set<int> sums;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 sums.insert(planks[i] + planks[j]);
//             }
//         }

//         for (int v : sums) {

//             map<int, int> tmp = mp;
//             int t = 0;

//             for (int j = 0; j < n; j++) {

//                 if (tmp[planks[j]] == 0)
//                     continue;

//                 if (planks[j] == v) {
//                     t++;
//                     tmp[planks[j]]--;
//                     continue;
//                 }

//                 tmp[planks[j]]--;

//                 int need = v - planks[j];

//                 if (tmp[need] > 0) {
//                     t++;
//                     tmp[need]--;
//                 }
//             }

//             ans = max(ans, t);
//         }
//         return ans;
//     }
// };

  //Optimized : O(n^2)
class Solution {
public:
    int maximumWidth(vector<int>& nums) {

        int n = nums.size();
        map<int, int> mp;
        for (auto it : nums)
            mp[it] += 1;
        vector<pair<int, int>> t(begin(mp), end(mp));

        int z = t.size();
        for (int i = 0; i < z; i += 1) {
            auto [n1, f1] = t[i];
            for (int j = i + 1; j < z; j += 1) {
                auto [n2, f2] = t[j];
                mp[n1 + n2] += min(f1, f2);
            }
            mp[2 * n1] += (f1 / 2);
        }

        int ans = 0;
        for (auto& [a, b] : mp) {
            ans = max(ans, b);
        }
        return ans;
    }
};
