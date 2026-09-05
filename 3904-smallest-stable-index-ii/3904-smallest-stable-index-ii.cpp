class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>Min(n);
        Min[n-1] = nums[n-1];
        for(int i =n-2 ; i>=0 ; i--){
            Min[i] = min(nums[i],Min[i+1]);
        }
        int Max = nums[0];
        for(int i =0 ; i<n ; i++){
            Max = max(nums[i],Max);
            int stable = Max - Min[i];
            if(stable<=k){
                return i;
            }
        }
       return -1; 
    }
};