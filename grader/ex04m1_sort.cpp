#include <bits/stdc++.h>
using namespace std;
int main(){
    int num[4] = {0},A1[4]={0},A2[4]={0},A3[4]={0};
    int n; cin >> n;
    vector <int> v(n+1);
    for(int i = 1;i<=n;i++){
        int t; cin >>t;
        v[i] = t;
        num[t] +=1;
    }
    for(int i = 1;i<=n;i++){
        if(i<=num[1]) A1[v[i]] +=1;
        else if(i<=num[1]+num[2]) A2[v[i]] +=1;
        else A3[v[i]] +=1;
    }
    int cnt = max((A1[2]+A1[3]+A2[3]),(A2[1]+A3[1]+A3[2]));
    cout << cnt << endl;
    return 0;
}