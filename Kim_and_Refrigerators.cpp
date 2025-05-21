#include <bits/stdc++.h>

using namespace std;

//10
//1 1 2 2 33 33 44 4 57 45 34 12 0 0 9 7 34 2 1 2 34 66 45 34 

struct point{
    int x, y;
};

int calculate_dist(point a, point b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}

//Call by reference is important for DP
int calculate_cost(vector<vector<int>>& dp, vector<vector<int>>& dist, int mask, int pos, int n){

    int visited_all = ((1<<n)-1) & ~(1<<1); //get all ones except 2nd bit;
    int ans = INT_MAX;

    if(dp[mask][pos]!=-1) return dp[mask][pos];

    if(mask == visited_all) return dist[pos][1];

    for(int i=0;i<n;i++){
        if(i==1) continue; //Skipping the destination point
        if((mask&(1<<i))==0){
            int new_ans = dist[pos][i] + calculate_cost(dp, dist, (mask|(1<<i)), i, n);
            ans = min(new_ans, ans);
        }
    }
    
    return dp[mask][pos] = ans;
}

int main(){

    int t = 1;

    while(t<=10){
        vector<point> points;
        int n;
        cin>>n;
        n+=2;
        //Taking Input
        for(int i=0;i<n;i++){
            point p;
            cin>>p.x>>p.y;
            points.push_back(p);
        }
        //Calculate Distance Matrix
        vector<vector<int>> dist(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) dist[i][j] = calculate_dist(points[i], points[j]);
        }
        //Using DP to Memoization
        vector<vector<int>> dp(1<<n, vector<int>(n, -1));

        cout<<"# "<<t<<" "<<calculate_cost(dp, dist, 1, 0, n)<<endl;
    
        t++;
    }   
}