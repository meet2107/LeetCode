#include <bits/stdc++.h>

unordered_map<char,char> m = {{')','('}, {']','['} , {'}', '{'}};

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(int i=0;i<str.length();i++){
            if(m.find(str[i]) == m.end()){
                s.push(str[i]);
            }
            else if(!s.empty() && m[str[i]] == s.top()){
                s.pop();
            }
            else{
                return false;
            }
        }

        return s.empty();
    }
};
