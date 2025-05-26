class Solution {
public:
    int maxDepth(string s) {
        int open = 0, ans=0;
        for(auto i : s){
            if(i == '('){
                open++;
                ans = max(ans,open);
            }
            else if(i==')'){
                open--;
            }
        }

        return ans;
    }
};
