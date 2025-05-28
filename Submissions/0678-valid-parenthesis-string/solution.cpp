class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int lmin = 0, lmax = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                lmin++;
                lmax++;
            }
            else if(s[i] == ')'){
                lmin--;
                lmax--;
            }
            else{
                lmin--;
                lmax++;
            }
            if(lmax < 0){
                return 0;
            }
            if(lmin < 0){
                lmin = 0;
            }
        }

        return lmin == 0;
    }
};
