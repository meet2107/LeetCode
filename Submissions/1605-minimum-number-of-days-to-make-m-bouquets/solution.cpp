class Solution {
public: 

    bool possible(vector<int> &a, int day, int k, int m){
        int bloomed = 0, b = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] <= day){
                bloomed++;
            }
            else{
                b += bloomed/k;
                bloomed = 0;
            }
        }

        b += bloomed/k;
        return b >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n){
            return -1;
        }

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low <= high){
            int mid = (low + high)/2;
            if(possible(bloomDay,mid,k,m)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};
