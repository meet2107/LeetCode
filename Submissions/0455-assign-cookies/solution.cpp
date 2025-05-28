class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // int cnt = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size(), m = s.size();
        int cookie=0,child=0;

        while(cookie<m && child<n){
            if(g[child]<=s[cookie]){
                // cnt++;
                child++;
            }
            cookie++;
        }

        return child;
    }
};
