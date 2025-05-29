class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1,1);
        int ans = 0;
        for(long i=2;i<n;i++){
            if(prime[i]){
                ans++;
                for(long j=i*i;j<n;j+=i){
                    prime[j] = 0;
                }
            }
        }

        return ans;
    }
};
