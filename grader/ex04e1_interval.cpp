#include <bits/stdc++.h>
using namespace std;
int main(){
    int n= 0;
    cin >> n;
    vector<pair <int,int> > v(n);
    for(int i =0;i<n;i++){
        cin >> v[i].second;
    }
    for(int i =0;i<n;i++){
        cin >> v[i].first;
    }
    sort(v.begin(),v.end());
    int cnt=0;
    int end = 0;
    for(auto [e, s] : v){
        if(end<=s){
            end = e;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}