#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,ll> > DP;
map<ll,ll > visited;
int Findd(ll i,map<ll,ll> &visited){
    if(visited[i]==-1) return i;
    visited[i]=Findd(visited[i],visited);
    return visited[i];
}
void Union(ll x,ll y,map<ll,ll > &visited){
    int s1 = Findd(x,visited);
    int s2 = Findd(y,visited);
    visited[s1]=s2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >>n;
    priority_queue<DP> pq;
    vector<ll> temp;
    int t =n;
    while(t--){
        ll a; cin>>a;
        temp.push_back(a);
        visited[a]=-1;
    }
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            ll XOR =temp[i]^temp[j];
            pq.push(make_pair(XOR,make_pair(temp[i],temp[j])));
        }
    }
    int cnt = 0;
    ll sum = 0;
    while(cnt<n-1){
        DP x = pq.top();
        pq.pop();
        ll t1 = x.second.first,t2=x.second.second;
        if(Findd(t1,visited)!=Findd(t2,visited)){
            Union(Findd(t1,visited),Findd(t2,visited),visited);
            cnt++;
            sum+=x.first;
        }
    }
    cout << sum << "\n";
    return 0;
}
    // while(pq.size()>0){
    //     DP e = pq.top();
    //     pq.pop();
    //     cout << e.first <<' '<<e.second.first<<' '<<e.second.second;
    //     cout << "\n";
    // }