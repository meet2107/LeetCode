class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = s;
        for(int i=0;i<s.length();i++){
            ans[i] = s[(i+k)%s.length()];
        }

        return ans;
    }
};
