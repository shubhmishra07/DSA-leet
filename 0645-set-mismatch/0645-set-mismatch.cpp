class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(n + 1, -1);
        int missing = -1 , duplicate = -1;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] != -1) {
                    duplicate = nums[i];
            }
            mp[nums[i]] = i;
        }
        for(int i =1 ; i<n+1 ; i++){
            if(mp[i]==-1){
                missing = i;
            }
        }
        return {duplicate, missing};
    }
};