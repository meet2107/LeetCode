class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {\
        int n = cardPoints.size();
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += cardPoints[i];
        }

        int cur = sum;
        for(int i=k-1;i>=0;i--){
            cur -= cardPoints[i];
            cur += cardPoints[n-k+i];

            sum = max(sum,cur);
        }

        return sum;
    }
};
