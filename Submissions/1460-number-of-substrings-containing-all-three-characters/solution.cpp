class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left=0,right=0;

        map<int,int> m;
        int ans = 0;

        while(right < n){
            m[s[right]]++;

            while(m.size() == 3){
                ans += n-right; // if valid till right then valid after it also
                m[s[left]]--;

                if(m[s[left]] == 0){
                    m.erase(s[left]);
                }
                left++;
            }

            right++;
        }

        return ans;
    }
};
