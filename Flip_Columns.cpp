#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    unordered_map<string, int> freq;

    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        string tmp = "";
        int cnt = 0;
        for(int j=0;j<m;j++){
            int val;
            cin>>val;
            if(val == 0) cnt++;
            tmp += (val + '0');
        }
        if(cnt <= k && ((k - cnt) % 2) == 0){
            freq[tmp]++;
            ans = max(ans, freq[tmp]);
        }
    }
    cout<<ans<<endl;
}
