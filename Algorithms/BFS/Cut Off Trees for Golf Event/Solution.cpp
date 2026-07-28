// Problem Link : https://leetcode.com/problems/cut-off-trees-for-golf-event/description/?envType=problem-list-v2&envId=d8khjo8v

/*
Ideas : I tried normal bfs with priority queue but what i observed is just
putting the adjacent min is not enough because we have to process the global min
so we must know what is the min and then try to reach there from 0,0 and then
from where we reach the next min and so on , so let me have it stored which
grids i have to explore and in what order



*/
class Solution {
public:
    vector<vector<int>> dist = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;
    vector<tuple<int, int, int>> tree;
    int bfs(vector<vector<int>>& forest, int cs, int ce, int ts, int te) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({cs, ce});
        visited[cs][ce] = true;

        int di = 0;

        while (!q.empty()) {

            int size = q.size();
            while (size--) {

                auto [r, c] = q.front();
                q.pop();
                if (r == ts && c == te) {
                    return di;
                }

                for (int i = 0; i < 4; i++) {
                    int nr = r + dist[i][0];
                    int nc = c + dist[i][1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (!visited[nr][nc] && forest[nr][nc] != 0) {
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }
                }
            }
            di++;
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest[0].size();
        int cost = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    tree.push_back({forest[i][j], i, j});
                }
            }
        }
        sort(begin(tree), end(tree));

        int cs = 0, ce = 0;
        for (auto [h, ts, te] : tree) {
            int ans = bfs(forest, cs, ce, ts, te);
            if (ans == -1)
                return -1;
            cost += ans;

            cs = ts;
            ce = te;

            forest[ts][te] = 1;
        }
        return cost;
    }
};
