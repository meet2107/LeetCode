class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);
        }

        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return cnt == V;
    }
};
