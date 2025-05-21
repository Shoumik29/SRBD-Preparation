#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int col){
    color[node] = col;

    for(int i=0;i<graph[node].size();i++){
        if(color[graph[node][i]] == -1){
            if(dfs(graph, color, graph[node][i], !col) == false) return false;
        }
        else{
            if(color[graph[node][i]] == col) return false;
        }
    }
    return true;
}

int main(){
    int n;
    while(cin>>n){
        if(!n) break;

        int m;
        cin>>m;

        vector<vector<int>> graph(n);
        vector<int> color(n, -1);
    
        for(int i=0;i<m;i++){
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
        }

        bool flag = true;
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(graph, color, i, 0) == false){
                    flag = false;
                    break;
                }
            }
        }

        if(flag) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }
}