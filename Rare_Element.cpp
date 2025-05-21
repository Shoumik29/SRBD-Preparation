#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& mat, vector<vector<int>> vis, int i, int j){
    int n = mat.size();
    queue<vector<int>> q;
    q.push({i, j, 1}); // rare elements have to be one
    vis[i][j] = 1;
    while(!q.empty()){
        vector<int> front = q.front();
        int x = front[0];
        int y = front[1];
        q.pop();
        int delx[4] = {0, 0, 1, -1};
        int dely[4] = {1, -1, 0, 0};
        for(int d=0;d<4;d++){
            int dx = x + delx[d];
            int dy = y + dely[d];
            if(dx >= 0 && dx < n && dy >= 0 && dy < n){
                if(mat[dx][dy] != 0 && vis[dx][dy] != 1){
                    mat[dx][dy] = max(mat[dx][dy], front[2] + 1);
                    vis[dx][dy] = 1;
                    q.push({dx, dy, front[2] + 1});
                }
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n, e;
        cin>>n>>e;

        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<pair<int, int>> elements;

        for(int i=0;i<e;i++){
            int x, y;
            cin>>x>>y;
            elements.push_back({x-1, y-1});
            //mat[x-1][y-1] = 1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cin>>mat[i][j];
        }
        
        for(auto el: elements) bfs(mat, vis, el.first, el.second);

        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != 0) ans = min(ans, mat[i][j]);
            }
        }

        cout<<ans-1<<endl;

        t--;
    }
}