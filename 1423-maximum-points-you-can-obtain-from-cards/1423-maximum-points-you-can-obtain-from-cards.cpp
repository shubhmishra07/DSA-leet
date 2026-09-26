class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int n = cardPoints.size();
        for(int i =0 ; i<k ; i++){
            lsum+=cardPoints[i];
        }
        int sum = lsum;
        for(int i= k-1; i>=0 ; i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[n-k+i];
            sum = max(sum , lsum+rsum);
        }
        return sum;
    }
};