#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, l;
map<int, vector<vector<int>>> paths;

void initPath(){
    paths[1] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    paths[2] = {{1, 0}, {-1, 0}};
    paths[3] = {{0, -1}, {0, 1}};
    paths[4] = {{-1, 0}, {0, 1}};
    paths[5] = {{1, 0}, {0, 1}};
    paths[6] = {{0, -1}, {1, 0}};
    paths[7] = {{0, -1}, {-1, 0}};
}

bool isPossible(vector<vector<int>>& grid, int nx, int ny, int ox, int oy){
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny]){
        for(auto pos: paths[grid[nx][ny]]){
            if(pos[0] + nx == ox && pos[1] + ny == oy) return true;
        }
    }
    return false;
}

int solve(vector<vector<int>>& grid){
    int ans = 0;
    queue<vector<int>> q;
    q.push({x, y, 1});
    vector<int> cur_pos;

    while(!q.empty()){
        cur_pos = q.front();
        q.pop();
        int ox = cur_pos[0], oy = cur_pos[1], ol = cur_pos[2];

        if(!grid[ox][oy] || ol > l) continue;

        ans++;
        int nx, ny;

        for(auto pos: paths[grid[ox][oy]]){
            nx = ox + pos[0];
            ny = oy + pos[1];
            if(isPossible(grid, nx, ny, ox, oy)){
                q.push({nx, ny, ol + 1});
            }
        }

        grid[ox][oy] = 0;
    }
    
    return ans;
}

int main(){
    initPath();
    int T;
    cin>>T;
    while(T){
        cin>>n>>m>>x>>y>>l;
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>grid[i][j];
        }

        cout<<solve(grid)<<endl;

        T--;
    }
}
