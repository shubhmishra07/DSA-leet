class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startX = r;
                    startY = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }
        
        int k = litters.size();
        int fullMask = (1 << k) - 1;
        if (fullMask == 0) return 0;

        vector<vector<vector<int>>> maxEnergy(m, vector<vector<int>>(n, vector<int>(1 << k, -1)));
        
        queue<vector<int>> q;
        q.push({startX, startY, 0, energy, 0});
        maxEnergy[startX][startY][0] = energy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr[0];
            int c = curr[1];
            int mask = curr[2];
            int e = curr[3];
            int steps = curr[4];
            
            if (mask == fullMask) return steps;
            if (e == 0) continue;
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int nextE = e - 1;
                    int nextMask = mask;
                    
                    if (classroom[nr][nc] == 'L') {
                        for (int i = 0; i < k; ++i) {
                            if (litters[i].first == nr && litters[i].second == nc) {
                                nextMask |= (1 << i);
                                break;
                            }
                        }
                    } else if (classroom[nr][nc] == 'R') {
                        nextE = energy;
                    }
                    
                    if (nextE > maxEnergy[nr][nc][nextMask]) {
                        maxEnergy[nr][nc][nextMask] = nextE;
                        q.push({nr, nc, nextMask, nextE, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};