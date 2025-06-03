class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long int MOD = (long long int)1e9+7;
        vector<pair<long long int,long long int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> pq;
        pq.push({0,0});

        vector<long long int> dist(n,1e18), ways(n,0);
        dist[0] = 0; 
        ways[0] = 1;

        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();

            long long int dis = f.first;
            long long int node = f.second;

            for(auto it : adj[node]){
                long long int adjn = it.first;
                long long int wt = it.second;

                // first visit
                if(dis+wt < dist[adjn]){
                    dist[adjn] = dis+wt;
                    ways[adjn] = ways[node];
                    pq.push({wt+dis,adjn});
                }
                // other visits
                else if(dis+wt == dist[adjn]){
                    ways[adjn] = (ways[adjn] + ways[node])%MOD;
                }
            }
        }

        return ways[n-1]%MOD;
    }
};
