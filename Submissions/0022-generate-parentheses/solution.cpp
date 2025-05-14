class Solution {
public:

    void rec(int open, int close, string s, int n, vector<string> &res){
        if(open == close && open + close == n*2){
            res.push_back(s);
            return;
        }

        if(open < n){
            rec(open+1,close,s+'(',n,res);
        }
        if(close < open){
            rec(open,close+1,s+')',n,res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        rec(0,0,"",n,res);
        return res;
    }
};
