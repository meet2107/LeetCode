class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        vector<int> f(26,0);
        for(auto i : tasks){
            f[i-'A']++;
        }

        sort(f.begin(),f.end());
        int maxi = f[25] - 1;
        int ans = maxi*n;

        for(int i=24;i>=0;i--){
            ans -= min(maxi,f[i]);
        }

        return ans<0 ? m : m+ans;
    }
};
