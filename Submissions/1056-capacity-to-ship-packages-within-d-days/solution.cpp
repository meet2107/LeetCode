class Solution {
public:

    bool check(vector<int> &weights, int days, int wt, int n){
        int day = 1;
        int sum = 0;

        for(int i=0;i<n;i++){
            // if(weights[i] <= wt){
            //     sum += weights[i];
            // }

            if(sum + weights[i] > wt){
                sum = weights[i];
                day++;
            }
            else{
                sum += weights[i];
            }
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low <= high){
            int mid = (low + high)/2;
            if(check(weights,days,mid,n)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};
