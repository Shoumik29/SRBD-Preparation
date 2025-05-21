#include <bits/stdc++.h>

using namespace std;

struct point{
    int x, y;
};

int cal_dist(point a, point b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}

int find_point(vector<point>& vec, point p){
    for(int i=0;i<vec.size();i++){
        if((vec[i].x == p.x) && (vec[i].y == p.y)) return i;
    }
    return -1;
}

void shortestPath(vector<vector<int>>& graph, vector<int>& dist, int s, int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for(int i=0;i<n;i++){
            if((cost + graph[node][i]) < dist[i]){
                dist[i] = (cost + graph[node][i]);
                pq.push({dist[i], i});
            }
        }
    }
}

int main(){
    int T;
    cin>>T;
    while(T){
        int n;
        cin>>n; 

        vector<vector<int>> graph(2*n+2, vector<int>(2*n+2, INT_MAX));
        vector<point> points;

        point s, d;
        cin>>s.x>>s.y>>d.x>>d.y;
        
        points.push_back(s);

        for(int i=0;i<n;i++){
            point a, b;
            int cost;
            cin>>a.x>>a.y>>b.x>>b.y>>cost;

            int indx_a = find_point(points, a);
            int indx_b = find_point(points, b);
            
            if(indx_a == -1){
                points.push_back(a);
                indx_a = points.size() - 1;
            }
            if(indx_b == -1){
                points.push_back(b);
                indx_b = points.size() - 1;
            }

            if(cost < graph[indx_a][indx_b]) graph[indx_a][indx_b] = cost;
            if(cost < graph[indx_b][indx_a]) graph[indx_b][indx_a] = cost;
        }

        points.push_back(d);

        for(int i=0;i<int(points.size());i++){
            for(int j=0;j<int(points.size());j++){
                int newDist = cal_dist(points[i], points[j]);
                if(graph[i][j] > newDist) graph[i][j] = newDist;
            }
        }

        vector<int> dist(int(points.size()), INT_MAX);
        
        shortestPath(graph, dist, 0, int(points.size()));
        
        cout<<dist[int(points.size() - 1)]<<endl;

        T--;
    }
}