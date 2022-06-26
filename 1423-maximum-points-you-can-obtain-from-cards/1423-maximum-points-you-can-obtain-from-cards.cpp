class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int sum1=sum;
        for(int i=k-1;i>=0;i--){
            sum1-=cardPoints[i];
            sum1+=cardPoints[n-k+i];
            sum=max(sum,sum1);
        }
        return sum;
    }
};