class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(char c : num){
            while(!s.empty() && k > 0 && s.top() > c){
                s.pop();
                k--;
            }
            s.push(c);
        }

        while(!s.empty() && k > 0){
            s.pop();
            k--;
        }

        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }

        reverse(ans.begin(),ans.end());
        return ans.empty() ? "0" : ans;
    }
};
