#include <bits/stdc++.h>
using namespace std;

int k;
bool isVirus(vector<int> v,int k){
    if (k==1){
        return v[0]==0 && v[1]==1;
    }
    int m = pow(2,k-1);
    vector<int> v1(m);
    for(int i =0;i<m;i++) v1[i]=v[i];

    vector<int> v2(v1);
    reverse(v2.begin(),v2.end());

    vector<int> v3(m);
    for(int i = 0;i<m;i++){
        v3[i] = v[i+m];
    }
    bool x = isVirus(v1,k-1);
    bool y = isVirus(v2,k-1);
    bool z = isVirus(v3,k-1);
    return((x||y)&&z);
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n >> k;
    int m = pow(2,k);
    vector<int> v(m);
    while(n--){
        for(int i =0;i<m;i++){
            int t; cin >> t;
            v[i] = t;
        }
        if(isVirus(v,k)){
            cout << "yes" <<"\n";
        }
        else cout << "no" <<"\n";

    }

    return 0;
}