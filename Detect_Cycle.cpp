#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cycle;
int min_sum = INT_MAX;

void dfs(int node, vector<vector<int>>& graph, vector<int>& global_visited, vector<int>& path_vis, vector<int>& path){
    global_visited[node] = 1;
    path.push_back(node);
    path_vis[node] = path.size() - 1;

    for(int i=0;i<graph[node].size();i++){
        if(path_vis[graph[node][i]] >= 0){
            vector<int> tmp;
            int sum = 0;

            for(int j=path_vis[graph[node][i]];j<path.size();j++){
                sum += path[j];
                tmp.push_back(path[j]);
            }
            if(sum < min_sum){
                min_sum = sum;
                cycle = tmp;
            }
            break;
        }
        else{
            dfs(graph[node][i], graph, global_visited, path_vis, path);
        }
    }
    path_vis[node] = -1;
    path.pop_back();
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> graph(n + 1);
    vector<int> global_visited(n + 1, 0);
    vector<int> path_vis(n + 1, -1);
    vector<int> path;

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    for(int i=0;i<n;i++){
        if(global_visited[i] != 1){
            dfs(i, graph, global_visited, path_vis, path);
        }
    }

    sort(cycle.begin(), cycle.end());
    for(auto val: cycle) cout<<val<<" ";
    cout<<endl;
}

// 10 11
// 1 2 2 3 3 4 4 5 5 6 3 7 7 5 2 8 8 9 9 10 10 8

// 10 11
// 1 2 2 3 3 4 4 5 5 6 7 3 5 7 2 8 8 9 9 10 10 8


