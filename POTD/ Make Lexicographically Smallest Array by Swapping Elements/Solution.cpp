// Probelm Link : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2026-08-29
/*

One observation that can be made is if we can group different numbers in some
pool then we can see that those elements can be sorted in ascending order to
make sure we have lexicographically smallest stuff....

like if lets say i put {3,2,1} in a pool p1

and i say the max limit for swap is 1   it is clear we can swap {3,2}
and {2,1} but we can't swap {3,1} directly but because 2 is there
we can eventually swap 1,3 also making our pool look like {1,2,3}

it can also be though as numbers = nodes , then which nodes are connected, just
to see the link / connectivity here.....


now if i can group numbers in a group and sort them , i have an order
rest is i have to fill back sorted groups in correct / possible indexes and we
are done i guess ......


Now how do we group ???? , i think we can simply sort the array and then
go as far right as possible if the diff <=limit becuase adjacent will have least
diff and till they have limited diff put them in a group and so on.....




*/
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<vector<int>> groups(n);
        vector<vector<int>> group_index(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }


        sort(begin(nums), end(nums));

        int i = 1;
        int gidx = 0;

        group_index[0].push_back(mp[nums[0]].back());
        groups[0].push_back(nums[0]);
        mp[nums[0]].pop_back();

        while (i < n) {
            if (nums[i] - nums[i - 1] > limit) {
                gidx++;
            }
            groups[gidx].push_back(nums[i]);
            group_index[gidx].push_back(mp[nums[i]].back());
            mp[nums[i]].pop_back();
            i++;
        }

        vector<int> ans(n, 0);

        for (vector<int>& v : group_index) {
            sort(begin(v), end(v));
        }

        for (int i = 0; i < groups.size(); ++i) {
            for (int j = 0; j < groups[i].size(); ++j) {
                int index = group_index[i][j];
                int value = groups[i][j];
                ans[index] = value;
            }
        }
        return ans;
    }
};
