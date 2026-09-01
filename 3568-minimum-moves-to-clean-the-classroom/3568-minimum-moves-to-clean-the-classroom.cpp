class Solution {
public:
    int maxEnergy[21][21][1 << 10];
  
    int minMoves(vector<string>& classroom, int energy) {
        int cntL = 0;
        int n = classroom.size();
        int m = classroom[0].size();
        vector<vector<int>> itemId(n, vector<int>(m, -1));
        int x = -1, y = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'L') {
                    itemId[i][j] = cntL++;
                } else if (classroom[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
        }
        
        if (cntL == 0) return 0;
        int targetMask = (1 << cntL) - 1;
        if (x == -1) return -1;
        
        memset(maxEnergy, -1, sizeof(maxEnergy));
        
        queue<tuple<int, int, int, int, int>> q;
        q.push({x, y, energy, 0, 0});
        maxEnergy[x][y][0] = energy;

        int dis[] = {1, 0, -1, 0, 1};
      
        while (!q.empty()) {
            auto [currX, currY, e, collected, used] = q.front();
            q.pop();
            
            if (collected == targetMask) return used;
            if (e < maxEnergy[currX][currY][collected]) continue;
            if (e == 0) continue;

            for (int d = 0; d < 4; d++) {
                int newx = currX + dis[d];
                int newy = currY + dis[d+1];

                if (newx >= 0 && newy >= 0 && newx < n && newy < m && classroom[newx][newy] != 'X') {
                    int newe = e - 1;
                    int newCollected = collected;
                     
                    if (classroom[newx][newy] == 'R') {
                        newe = energy;
                    } else if (classroom[newx][newy] == 'L') {
                        int pos = itemId[newx][newy];
                        newCollected |= (1 << pos);
                    }

                    if (newe > maxEnergy[newx][newy][newCollected]) {
                        maxEnergy[newx][newy][newCollected] = newe;
                        q.push({newx, newy, newe, newCollected, used + 1});
                    }
                }
            }
        }
        return -1;
    }
};