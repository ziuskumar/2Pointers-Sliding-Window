class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxl = 0;
        int n = cardPoints.size();
        int lsum = 0 , rsum = 0;

        for(int i=0; i<k ;i++){
            lsum = lsum + cardPoints[i];
            maxl = lsum;
        }

        int ridx = n-1;

        for(int i=k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[ridx];

            ridx--;
            maxl = max(maxl, (rsum+lsum));
        }
        return maxl;
    }
};
