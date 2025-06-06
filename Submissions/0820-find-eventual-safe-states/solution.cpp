class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse the graph then simple topo sort
        int n = graph.size();
        vector<int> adj[n+1];
        for(int i=0; i<n; i++){
            for(auto edge: graph[i]){
                adj[edge].push_back(i);
            }
        }


        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};
