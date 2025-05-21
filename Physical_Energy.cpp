#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>>& dp, vector<int>& t, vector<int>& cost, int h, int d){
    if(h < 0) return 1e9;
    if(d == 0) return 0;

    if(dp[h][d] != -1) return dp[h][d];

    int time = 1e9;
    for(int i=0;i<t.size();i++){
        time = min(time, t[i] + solve(dp, t, cost, h - cost[i], d - 1));
    }

    return dp[h][d] = time;
}

int main(){

    int n, h, d;
    cin>>n>>h>>d;

    vector<int> time(n), st_cost(n); 
    for(int i=0;i<n;i++) cin>>time[i]>>st_cost[i];

    vector<vector<int>> dp(h+1, vector<int>(d+1, -1));

    int ans = solve(dp, time, st_cost, h, d);

    cout<<ans<<endl;
}

/*

5 14 4
200 4
210 5
230 2
235 3
215 6

*/