class Solution {
public:

    bool check(string s, int l, int r){
        while(l < r){
            if(s[l++] !=  s[r--]){
                return false;
            }
        }
        return true;
    }

    void rec(int ind, string s, vector<string> &temp, vector<vector<string>> &ans){
        if(ind == s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind+1;i<=s.length();i++){
            if(check(s,ind,i-1)){
                temp.push_back(s.substr(ind,i-ind));
                rec(i,s,temp,ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        rec(0,s,temp,ans);
        return ans;
    }
};
