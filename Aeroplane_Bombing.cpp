#include <bits/stdc++.h>

using namespace std;

int maxPoints(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j, int b){
    if(i < 0) return 0;

    if(dp[i][j][b] != -1) return dp[i][j][b];

    if(b >= 1 && b <= 5) b++;

    int max_points = -1e9;

    for(int indx=-1;indx<=1;indx++){
        int points;

        int dj = j + indx;
        if(dj >= 0 && dj < 5){
            if(grid[i][dj] == 0) points = maxPoints(grid, dp, i - 1, dj, b);
            else if(grid[i][dj] == 1) points = 1 + maxPoints(grid, dp, i - 1, dj, b);
            else if(grid[i][dj] == 2 && b == 0) points = maxPoints(grid, dp, i - 1, dj, b + 1);
            else if(grid[i][dj] == 2 && b == 6) return 0;
            else if(grid[i][dj] == 2 && b > 0) points = maxPoints(grid, dp, i - 1, dj, b);
            max_points = max(max_points, points);
        }
    }
    return dp[i][j][b] = max_points;
}

int main(){
    int T, t = 1;
    cin>>T;
    while(t <= T){
        int n;
        cin>>n;

        vector<vector<int>> grid(n, vector<int>(5, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++) cin>>grid[i][j];
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(5, vector<int>(7, -1)));

        cout<<"#"<<t<<" "<<maxPoints(grid, dp, n - 1, 2, 0)<<endl;

        t++;
    }
}