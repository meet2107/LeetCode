class Solution {
public:

    long long help(vector<int> &piles, int rate){
        long long ans = 0;
        for(int i=0;i<piles.size();i++){
            ans += ceil((double)(piles[i]) / (double)(rate));
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low <= high){
            int mid = (low + high)/2;

            long long total = help(piles,mid);
            if(total > h){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return low;
    }
};
