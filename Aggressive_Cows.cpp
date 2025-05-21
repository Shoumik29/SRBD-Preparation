#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> stalls, int dist, int cows){
    int cntCows = 1, last = stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i] - last >= dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;

        vector<int> stalls(n);
        for(int i=0;i<n;i++) cin>>stalls[i];

        sort(stalls.begin(), stalls.end());
        // Binary Search
        int low = 1, high = stalls[n - 1] - stalls[0];
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(stalls, mid, c)) low = mid + 1;
            else high = mid - 1;
        }

        cout<<high<<endl;
    }
}