class Solution {
public:
    long long maximumPoints(vector<int>& a, int cur) {
        long long ans = 0;
        long long n = a.size();

        sort(a.begin(),a.end());

        if(cur < a[0]){
            return 0;
        }

        ans += cur;

        for(int i=1;i<n;i++){
            ans += a[i];
        }

        return (long long)(ans/a[0]);
    }
};
