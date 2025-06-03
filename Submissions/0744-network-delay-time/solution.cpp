class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        vector<int> dist(n+1,1e9);
        dist[k] = 0;

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();

            int dis = t.first;
            int node = t.second;

            for(auto it : adj[node]){
                int adjn = it.first;
                int wt = it.second;

                if(dis+wt < dist[adjn]){
                    dist[adjn] = dis+wt;
                    pq.push({dis+wt,adjn});
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9){
                return -1;
            }

            ans = max(ans,dist[i]);
        }

        return ans;
    }
};
