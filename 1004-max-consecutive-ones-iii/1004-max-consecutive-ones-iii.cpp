class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        int currentlen = 0;
        int temp = 0; 
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (k > 0) {
                    k--;
                    currentlen++;
                } else {
                    while (nums[temp] != 0) {
                        temp++;
                        currentlen--;
                    }
                    temp++;
                }
            } else {
                currentlen++;
            }
            maxlen = max(maxlen, currentlen);
        }
        return maxlen;
    }
};