class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> f(256,0);
        for(int i=0;i<m;i++){
            f[t[i]]++;
        }

        int ans = INT_MAX, ind = -1, len = 0;
        int l=0,r=0;

        while(r < n){
            if(f[s[r]] > 0){
                len++;
            }
            f[s[r]]--;

            while(len == m){
                if(r-l+1 < ans){
                    ans = r-l+1;
                    ind = l;
                }

                f[s[l]]++;
                if(f[s[l]] > 0){
                    len--;
                }
                l++;
            }

            r++;
        }

        return ind == -1 ? "" : s.substr(ind,ans);
    }
};
