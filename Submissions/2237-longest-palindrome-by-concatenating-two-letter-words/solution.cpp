class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        for(auto i : words){
            m[i]++;
        }

        int count=0,pal=0;
        for(auto& [w,f] : m){
            string s = w;
            reverse(s.begin(),s.end());

            if(w==s){
                count += (f/2)*4;
                if(f%2){
                    pal = 1;
                }
            }
            else if(w<s && m.count(s)){
                count += min(f,m[s])*4;
            }
        }
        return count + pal*2;
    }
};
