class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> ms;
        map<char,int> mt;

        for(int i=0;i<s.length();i++){
            if(ms.find(s[i]) == ms.end()){
                ms[s[i]] = i;
            }
            if(mt.find(t[i]) == mt.end()){
                mt[t[i]] = i;
            }

            if(ms[s[i]] != mt[t[i]]){
                return false;
            }
        }

        return true;
    }
};
