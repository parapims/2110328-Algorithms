#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void cost(vector<vector<ll> > &v,int r,int c){
    if(v[r][c-1]==-1) cost(v,r,c-1);
    v[r][c] = v[r][c-1]+v[c][c];
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,k; cin >> n >> m >>k;
    vector<vector<ll> > v(n,vector<ll>(n,-1));
    vector<ll> fn(n+1,0);
    fn[0]=0;    
    for(int i =0;i<n;i++){
        ll a; cin >> a;
        v[i][i]=a+k;
        fn[i+1]=fn[i]+a;
    }

    while(m--){
        ll l,budjet; cin >> l >> budjet;
        int cnt = 0;
        if(v[l][l]>budjet) {cout << 0 << "\n";}
        else{
            int left = l,right=n;
            while(left<right){
                int mid = left+((right-left)/2);
                if(v[l][mid]==-1) cost(v,l,mid);
                else{
                    if(v[l][mid]<=budjet){
                        left = mid+1;
                    }
                    else{
                        right = mid;
                    }
                }
            }
            // cout << left <<endl;
            cout<<fn[left]-fn[l]<<endl;
            
        }
    }
    // for(size_t i = 0;i<fn.size();i++){
    //     cout << fn[i]<<' ';
    // }

    // cout << endl;
    // for(auto e:v){
    //     for (auto f:e) cout << f <<' ';
    //     cout << "\n";
    //}
    return 0;
}