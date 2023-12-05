#include <bits/stdc++.h>
using namespace std;
vector <long long int> v(10000001,-1);
long long int without11 (long long int n){
    if(n==1) return 3;
    if(n==2) return 7;
    if(v[n-1]==-1) without11(n-1);
    if(v[n-2]==-1) without11(n-1);
    v[n]= ((2*v[n-1])+v[n-2])%100000007;
    return v[n];
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    v[1]=3;
    v[2]=7;
    long long int n; cin >> n;
    cout << without11(n);
}