class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<=min(n-1,k);i++){
            if(mp[nums[i]]==1){
                return true;
            }
            mp[nums[i]]++;
        }

        for(int i=k+1;i<n;i++){
            mp[nums[i-k-1]]--;
            if(mp[nums[i]]==1){
                return true;
            }
            mp[nums[i]]++;
        }
        return false;


        
    }
};