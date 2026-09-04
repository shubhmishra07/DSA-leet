class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int Max = *max_element(nums.begin(), nums.begin() + i);
            int Min = *min_element(nums.begin() + i, nums.end());
            int stable = Max - Min;
            if (stable <= k) {
                return i;
            }
        }
        return ans;
    }
};