class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        map<char,int> m;
        int ans=0,i=0,maxi=0;

        for(int j=0;j<n;j++){
            m[s[j]]++;

            maxi = max(maxi,m[s[j]]);

            while((j-i+1) - maxi > k){
                m[s[i]]--;
                i++;
            }

            ans = max(ans,j-i+1);
        }
        
        return ans;
    }
};
