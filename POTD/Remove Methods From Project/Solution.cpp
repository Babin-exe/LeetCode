// Problem Link : https://leetcode.com/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {

        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for (auto it : inv) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            deg[v]++;
        }

        vector<int> v(n, false);
        v[k] = true;
        queue<int> que;
        que.push(k);

        while (!que.empty()) {
            int node = que.front();
            que.pop();
            for (auto& ne : adj[node]) {
                deg[ne]--;

                if (!v[ne]) {
                    v[ne] = true;
                    que.push(ne);
                }
            }
        }

        bool sus = false;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (v[i] && deg[i] > 0) {
                sus = true;
                break;
            }
            if (!v[i]) {
                ans.push_back(i);
            }
        }

        if (sus) {
            vector<int> temp(n);
            for (int i = 0; i < n; i++) {
                temp[i] = i;
            }
            return temp;
        } else {
            return ans;
        }
    }
};
