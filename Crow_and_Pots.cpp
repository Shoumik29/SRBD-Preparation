#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, k;
        cin>>n>>k;

        vector<int> pots(n);
        for(int i=0;i<n;i++) cin>>pots[i];

        sort(pots.begin(), pots.end());

        int front_sum = 0, back_sum = 0;

        for(int i=0;i<pots.size();i++){
            if(i < k) front_sum += pots[i];
            else front_sum += pots[k - 1];
        }
        for(int i=pots.size()-1;k>0;i--, k--) back_sum += pots[i];

        cout<<min(front_sum, back_sum)<<endl;
    }
}