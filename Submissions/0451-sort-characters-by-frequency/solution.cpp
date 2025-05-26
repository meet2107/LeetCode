class Solution {
public:

    string frequencySort(string s) {
        auto cmp = [](const pair<char,int> &p1, const pair<char,int> &p2){
            return p1.second < p2.second;
        };
        int n = s.length();
        map<char,int> m;
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq(cmp);
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }

        // sort(m.begin(),m.end(),comp);
        // for(auto i : m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }

        for(auto i : m){
            pq.push({i.first,i.second});
        }

        string ans = "";
        while(!pq.empty()){
            pair<char,int> p = pq.top();
            pq.pop();

            ans.append(p.second,p.first);
        }

        return ans;
    }
};
