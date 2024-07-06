#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int target) {
        ll n = nums.size();
        ll result = 0;
        ll cur = (1LL << 32) - 1; 
        vector<ll> count(32, 0);
        
        for (ll i = 0; i < n; i++) {
            cur &= nums[i];
            bool t = true;
            ll sc = i + 1;
            ll maxi = 0; 
            
            for (ll j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    count[j]++;
                }
                else {
                    count[j] = 0;
                }
                
                bool t1 = target & (1 << j);
                bool t2 = cur & (1 << j);
                
                if (!t1 && t2) {
                    t = false;
                }
                else if (t1 && !t2) {
                    sc = min(sc, count[j]);
                } 
                else if (!t1 && !t2) {
                    maxi = max(maxi, count[j]);
                }
            }
            
            if (t) {
                if (maxi < sc) {
                    result += (sc - maxi);
                }
            }
        }
        
        return result;
    }
};
