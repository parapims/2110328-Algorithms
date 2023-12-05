#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
int node,deg1,deg2;

void dfs(int i,vector<bool> &visit){
    visit[i]=true;
    node++;
    if(adj[i].size()==1) deg1++;
    if(adj[i].size()==2) deg2++;
    for(auto e:adj[i]){
        if(!visit[e]){
            dfs(e,visit);
        }
    }
}
int main(){
    int v,e,cnt=0;
    cin >> v >> e;
    vector<bool> visit(v,false);
    adj.resize(v);
    while(e--){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i =0;i<v;i++){
        node = 0;
        deg1 = 0;
        deg2 = 0;
        if(!visit[i]){
            dfs(i,visit);
            if(node==1||(deg1==2 && deg2==node-2)){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}