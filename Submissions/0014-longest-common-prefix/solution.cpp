class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string f = strs[0];
        string l = strs[n-1];

        int mini = min(f.length(),l.length());
        int i=0;
        while(i<mini && l[i] == f[i]){
            i++;
        }

        return f.substr(0,i);
    }
};
