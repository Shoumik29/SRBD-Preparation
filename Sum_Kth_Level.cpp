#include <iostream>

using namespace std;

int tonum(string str){
    int num=0;
    for(int i=0;i<str.size();i++){
        num=num*10+(int(str[i])-48);
    }
    return num;
}

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    int level = -1;
    int sum = 0;
    int n = s.size();

    for(int i=0;i<n;i++){
        if(s[i] == '(') level++;
        else if(s[i] == ')') level--;
        else if(level == k){
            string tmp = "";
            while(i < n && s[i] >= '0' && s[i] <= '9'){
                tmp += s[i];
                i++;
            }
            i--;
            sum += tonum(tmp); // stoi can be used but "" this causes problem
        }
    }

    cout<<sum<<endl;
}