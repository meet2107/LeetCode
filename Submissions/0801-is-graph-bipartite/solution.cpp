class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>&color){
        color[node] = col;

        for(auto edge: graph[node]){
            if(color[edge] == -1){
                if(dfs(edge, !col, graph, color)==false) return false;
            }
            else if(color[edge] == col) return false;
        }
        return true;
    }
    bool bfs(int node, int col, vector<vector<int>>& graph, vector<int>&color){
        queue<pair<int,int>>qu;
        qu.push({node,col});
        color[node] = col;

        while(!qu.empty()){
            int num = qu.front().first;
            int curr_col = qu.front().second;
            qu.pop();

            for(auto edge: graph[num]){
                if(color[edge] == -1){
                    color[edge] = !curr_col;
                    qu.push({edge,color[edge]});
                }
                else if(color[edge] == curr_col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(bfs(i,0,graph,color)==false) return false;
            }
        }
        return true;
    }
};
