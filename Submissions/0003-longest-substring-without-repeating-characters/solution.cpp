class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;

        vector<int> m(256,-1);

        int i=0,j=0;
        while(j < n){
            if(m[s[j]] != -1){
                i = max(m[s[j]]+1,i);
            }

            m[s[j]] = j;
            ans = max(ans,j-i+1);
            j++;

            // if(s[i] != s[j]){
            //     j++;
            // }
            // else if(s[i] == s[j]){
            //     ans = max(ans,j-i);
            //     i = j;
            //     j++;
            // }
        }

        return ans;
    }
};
