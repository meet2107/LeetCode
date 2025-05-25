class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int rank = 0;
        int prev = INT_MIN;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            if(top.first != prev){
                rank++;
            }

            ans[top.second] = rank;
            prev = top.first;
        }

        return ans;
    }
};
