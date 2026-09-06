class Solution {
public:
    using ll = long long;

    struct cmp {
        bool operator()(const auto& a, const auto& b) {
            return get<0>(a) > get<0>(b);
        }
    };

    ll inf = 1e18;

    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue< tuple<ll,int,int,int,int>, vector<  tuple<ll,int,int,int,int>> ,cmp >pq;
        vector<vector<vector<vector<ll>>>>dist(m, vector<vector<vector<ll>>>( n, vector<vector<ll>>( k + 1, vector<ll>(5, inf)) ));

        pq.push({grid[0][0], 0, 0, 0, 0});
        dist[0][0][0][0] = grid[0][0];

        int dir[] = {1, 0, -1, 0, 1};

        while (!pq.empty()) {
            auto [cost, x, y, turnUsed, usedDir] = pq.top();
            pq.pop();

            if (cost != dist[x][y][turnUsed][usedDir])
                continue;

            for (int d = 0; d < 4; d++) {
                int newx = x + dir[d];
                int newy = y + dir[d + 1];

                if (newx < 0 || newy < 0 || newx >= m || newy >= n)
                    continue;

                int currDir = d + 1;
                int newTurnUsed = turnUsed;

                if (usedDir != 0 && usedDir != currDir)
                    newTurnUsed++;

                if (newTurnUsed > k)
                    continue;

                ll newCost = cost + grid[newx][newy];

                if (newCost < dist[newx][newy][newTurnUsed][currDir]) {
                    dist[newx][newy][newTurnUsed][currDir] = newCost;
                    pq.push({newCost,newx,newy,newTurnUsed, currDir});
                }
            }
        }

        ll ans = inf;

        for (int turn = 0; turn <= k; turn++) {
            for (int d = 0; d <= 4; d++) {
                ans = min(ans, dist[m - 1][n - 1][turn][d]);
            }
        }

        return ans == inf ? -1 : (int)ans;
    }
};