#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n,m,k,w,t; cin >>n>>m>>k>>w;
    vector<int> mon(n+1,0);
    vector<int> tow;
    vector<int> temp;
    for(int i = 0;i<m;i++){
        cin >>t;
        temp.push_back(t);
    }
    for(auto e:temp){
        cin>>t;
        mon[e] = t;
    }
    while (k--){
        cin >> t;
        tow.push_back(t);
    }
    for(auto e:tow){
        for(int i =max(e-w,1);i<=e+w;i++){
            if (mon[i]>0) {
                mon[i]--;
                break;
            }
        }
    }
    int sum = 0;
    for(auto e:mon) sum+=e;
    cout << sum;
    return 0;
}