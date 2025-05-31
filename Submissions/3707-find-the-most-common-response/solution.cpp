class Solution {
public:
    string findCommonResponse(vector<vector<string>>& r) {
        int n = r.size();
        map<string,int> m;
        for(int i=0;i<n;i++){
            set<string> s(r[i].begin(),r[i].end());
            for(auto i : s){
                m[i]++;
            }
        }

        int maxi = 0;
        for(auto i : m){
            maxi = max(maxi,i.second);
        }

        vector<string> ans;
        for(auto i : m){
            if(i.second == maxi){
                ans.push_back(i.first);
            }
        }

        return *min_element(ans.begin(),ans.end());
    }
};
