class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> p1, p2;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) p1.push_back({i, j});
                if (img2[i][j] == 1) p2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> count;
        int maxOverlap = 0;

        for (auto& a : p1) {
            for (auto& b : p2) {
                pair<int, int> vec = {b.first - a.first, b.second - a.second};
                count[vec]++;
                maxOverlap = max(maxOverlap, count[vec]);
            }
        }

        return maxOverlap;
    }
};