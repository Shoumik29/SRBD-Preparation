#include <bits/stdc++.h>

using namespace std;

int maxPoints(vector<int>& b, vector<vector<int>>& dp, int i, int j){
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int max_cost = INT_MIN;
    for(int indx=i;indx<=j;indx++){
        int cost;
        if(i == 1 && j == int(b.size() - 2)){
            cost = b[indx] + maxPoints(b, dp, i, indx - 1) + maxPoints(b, dp, indx + 1, j);
        }
        else cost = b[i - 1] * b[j + 1] + maxPoints(b, dp, i, indx - 1) + maxPoints(b, dp, indx + 1, j);
        max_cost = max(max_cost, cost);
    }
    return dp[i][j] = max_cost;
}

int main(){
    int n;
    cin>>n;

    vector<int> ballons;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        ballons.push_back(val);
    }

    ballons.insert(ballons.begin(), 1);
    ballons.push_back(1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout<<maxPoints(ballons, dp, 1, int(ballons.size() - 2))<<endl;
}