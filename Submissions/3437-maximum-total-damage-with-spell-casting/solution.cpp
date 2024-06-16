class Solution {
public:
    long long maximumTotalDamage(vector<int>& a) {
        //sort(power.begin(),power.end());
       /* if(power.empty()){
            return 0;
        }*/
        
        //sort(power.begin(),power.end());
        
        /*map<int,long long> m;
        //long long ans = 0;
        
        //int n = power.size();
        for(long long i : power){
            m[i] += i;
           // ans = max(ans,i);
        }
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(const auto& i : m){
            mini = min(mini,i.first);
            maxi = max(maxi,i.first);
        }
        
        //vector<long long> dp(maxi+1,0);
        
        long long prev3 = 0, prev2 = 0, prev1 = 0;
        
        //if(m.find(1) != m.end()) dp[1] = m[1];
        for(int i=mini;i<=maxi;i++){
            long long d = m.find(i) != m.end() ? m[i] : 0;
            long long nt = prev1;
            long long t = d + (i > 2 ? prev3 : 0);
            long long temp = max(t,nt);
            
            
            prev3 = prev2;
            prev2 = prev1;
            prev1 = temp;
        }
        
        return prev1;*/

        /*sort(a.begin(), a.end());
        
        unordered_map<int, int> m;
        for (int num : a) {
            m[num]++;
        }
        
        vector<pair<int, int>> v;
        for (const auto& entry : m) {
            v.push_back(make_pair(entry.first, entry.second));
        }
        
        int n = v.size();
        vector<long long> dp(n + 3, 0);
        
        dp[0] = static_cast<long long>(v[0].first) * v[0].second;
        
        for (int i = 1; i < n; i++) {
            long long tk, nt;
            nt = dp[i - 1];
            tk = static_cast<long long>(v[i].first) * v[i].second;
            
            for (int j = i - 1; j >= 0; --j) {
                if (abs(v[i].first - v[j].first) > 2) {
                    tk += dp[j];
                    break;
                }
            }
            
            dp[i] = max(tk, nt);
        }
        
        return dp[n-1];*/
        
        map<long long, long long> m;
        for(auto i : a){
            m[i]++;
        }
        
        vector<long long> v;
        map<long long, long long> mp;
        
        for(auto& [i,j] : m){
            v.push_back(i);
        }
        
        sort(v.begin(),v.end());
        
        vector<long long> dp(v.size(),0);
        
        dp[0] = v[0]*m[v[0]];
        
        mp[v[0]] = 0;
         
        long long res = dp[0];
        for(int i=1;i<v.size();i++){
            long long j = v[i], curr = j * m[j], tk = curr;
            
            if(mp.count(j-2)){
                tk = curr + (mp[j-2]>0 ? dp[mp[j-2]-1] : 0);
            }
            
            else if(mp.count(j-1)){
                tk = curr + (mp[j-1]>0 ? dp[mp[j-1]-1] : 0);
            }
            else{
                tk = curr + dp[i-1];
            }
            
            long long nt = dp[i - 1];
            
            dp[i] = max(tk, nt);
            
            mp[j] = i;  
            res = max(res, dp[i]);

        }
        
        return res;
    }
};
