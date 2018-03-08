class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), color=0;      // number of nodes
        vector<int> colors(n, -1);          // color the node, where -1 is none, 0 is blue colored, and 1 is red colored
        // in case the graph are not fully connected
        for(int i=0; i<n; ++i){
            if(colors[i]==-1 && !validcolor(graph, colors, color, i))
                return false;
        }
        return true;
    }
    // DFS serach
    bool validcolor(vector<vector<int>>& graph, vector<int>& colors, int color, int node){
        if(colors[node]!= -1)   {return colors[node]==color;}
        colors[node]=color;
        for(auto next: graph[node]){
            if(!validcolor(graph, colors, 1-color, next))   {return false;}
        }
        return true;
    }
};