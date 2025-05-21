#include <bits/stdc++.h>

using namespace std;


//Call by reference is important for DP
int cost_calculation(vector<vector<int>>& dp, vector<vector<int>>& dist, int mask, int pos, int n){
    
    int visited_all = (1<<n)-1;
    int ans = INT_MAX;

    if(dp[mask][pos]!=-1) return dp[mask][pos];

    if(mask == visited_all) return dist[pos][0];

    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0){
            int new_ans = dist[pos][i] + cost_calculation(dp, dist, (mask|(1<<i)), i, n);
            ans = min(ans, new_ans);
        }
    }

    return dp[mask][pos] = ans;
}

int main(){

    int t;
    cin>>t;
    while(t){

        int n;
        cin>>n;
        vector<vector<int>> dist(n, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cin>>dist[i][j];
        }

        vector<vector<int>> dp((1<<n), vector<int>(n, -1));
        
        cout<<cost_calculation(dp, dist, 1, 0, n)<<endl;

        t--;
    }
}