class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minDist = INT_MAX;
        int ans = -1;

        for (int i = 0; i < drones.size(); i++) {
            int dist = abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]);
            int range = drones[i][2];
            if (dist <= range && dist < minDist) {
                minDist = dist;
                ans = i;
            }
        }

        return ans;
    }
};