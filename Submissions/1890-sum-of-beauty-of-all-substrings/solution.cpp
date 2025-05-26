class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            map<char,int> m;
            for(int j=i;j<n;j++){
                m[s[j]]++;

                int mf = INT_MIN;
                int lf = INT_MAX;

                for(auto i : m){
                    mf = max(mf,i.second);
                    lf = min(lf,i.second);
                }

                ans += mf-lf;
            }
        }

        return ans;
    }
};
