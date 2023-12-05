#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >>n;
    vector<ll> road(n);
    vector<bool> visited(n,false);
    vector<ll> Max(n,-1);
    for(int i =0;i<n;i++){
        cin >>road[i];
    }
    Max[0]=0;
    ll ans=0;
    for(int r=0;r<n;r++){
        ll max_price = -1;
        ll now;
        for(int i=0;i<n;i++){
            if(Max[i]>max_price &&!visited[i]){
                max_price=Max[i];
                now = i;
            }

        }
        visited[now]=true;
        ans+=Max[now];
        for(int j=0;j<n;j++){
            if(!visited[j]){
                ll candidate = road[now]^road[j];
                if(candidate>Max[j]){
                    Max[j]=candidate;
                }
            }
        }
    }
    cout << ans <<' ';
    return 0;
}