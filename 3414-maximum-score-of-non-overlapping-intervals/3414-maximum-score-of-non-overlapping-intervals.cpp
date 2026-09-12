#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

    struct DPValue {
        long long weight = 0;
        vector<int> indices;

        bool operator<(const DPValue& other) const {
            if (weight != other.weight) return weight < other.weight;
            return indices > other.indices; 
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            return a.id < b.id;
        });

        vector<int> next_valid(n);
        vector<int> lefts(n);
        for (int i = 0; i < n; ++i) lefts[i] = arr[i].l;

        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(lefts.begin() + i + 1, lefts.end(), arr[i].r);
            next_valid[i] = distance(lefts.begin(), it);
        }

        vector<vector<DPValue>> dp(n + 1, vector<DPValue>(5));

        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {

                DPValue best = dp[i + 1][k];

                DPValue take;
                int nxt = next_valid[i];
                take.weight = arr[i].weight + dp[nxt][k - 1].weight;

                take.indices = dp[nxt][k - 1].indices;
                take.indices.push_back(arr[i].id);
                sort(take.indices.begin(), take.indices.end());

                if (best < take) {
                    best = take;
                }
                dp[i][k] = best;
            }
        }

        return dp[0][4].indices;
    }
};