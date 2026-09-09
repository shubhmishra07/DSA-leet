class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = INT_MAX;
        bool hasOdd = false;

        for (int x : nums1) {
            if (x % 2 != 0) {
                hasOdd = true;
            }
            minVal = min(minVal, x);
        }

        if (minVal % 2 != 0) {
            return true;
        }

        return !hasOdd;
    }
};