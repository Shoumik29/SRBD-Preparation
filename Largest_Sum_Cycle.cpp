#include <bits/stdc++.h>

using namespace std;

int max_sum = INT_MIN;

void dfs(vector<vector<pair<int, int>>>& adj, vector<int>& vis, vector<int>& path_vis, int node, int sum){
    vis[node] = 1;
    path_vis[node] = sum;
    for(auto nd: adj[node]){
        if(vis[nd.first] == -1){
            sum += nd.second;
            dfs(adj, vis, path_vis, nd.first, sum);
        }
        else if(path_vis[nd.first] != -1){
            max_sum = max(max_sum, ((sum + nd.second) - path_vis[nd.first]));
        }
    }
    path_vis[node] = -1;
}

int main(){
    int n, e;
    cin>>n>>e;

    vector<vector<pair<int, int>>> adj(n+1);
    int u, v, w;
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }

    vector<int> visited(n+1, -1);
    vector<int> path_visited(n+1, -1);

    for(int i=1;i<n;i++){
        if(visited[i] == -1){
            dfs(adj, visited, path_visited, i, 0);
        }
    }

    cout<<max_sum<<endl;

}




/*

10 12
1 2 1
2 3 2
3 4 3
4 5 4
5 6 5
6 7 1
5 7 6
7 3 7
2 8 2
8 9 8
9 10 9
10 8 10

*/