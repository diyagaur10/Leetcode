class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, l =0, r = cardPoints.size()-1;
        while(k--){
            if(cardPoints[l] > cardPoints[r]){
                sum+= cardPoints[l];
                l++;
            }
            else{
                 sum += cardPoints[r];
                 r--;
            }
        }
        return sum;
    }
};