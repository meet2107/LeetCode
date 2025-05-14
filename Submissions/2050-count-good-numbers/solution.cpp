class Solution {
public:

    const int MOD = 1e9+7;

    long long power(long long x, long long n){
        long long ans = 1;
        x %= MOD;

        while(n){
            if(n & 1){
                ans = (ans*x)%MOD;
            }

            x = (x*x)%MOD;
            n >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        long long e = power(5,even);
        long long o = power(4,odd);

        return (o*e)%MOD;
    }
};
