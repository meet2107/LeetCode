class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        int bal = 0;

        for(int i=0;i<n;i++){
            if(s[i] ==  '('){
                if(bal > 0){
                    ans += s[i];
                }
                bal++;
            }
            else if(s[i] == ')'){
                bal--;
                if(bal > 0){
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};
