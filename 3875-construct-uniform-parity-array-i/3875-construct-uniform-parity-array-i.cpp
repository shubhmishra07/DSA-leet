class Solution {
public:
    bool allEven(vector<int>& nums1){
        for(int i =0 ; i< nums1.size() ; i++){
            if(nums1[i] %2 != 0){
                return false;
            }
        }
        return true;
    }

    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};