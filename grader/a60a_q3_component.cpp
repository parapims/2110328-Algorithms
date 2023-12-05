#include <bits/stdc++.h>
using namespace std;
void component(vector<int> adj[],vector <bool> &visit,int i){
    visit[i]=true;
    for(auto e:adj[i]){
        if(!visit[e]) component(adj,visit,e);
    }
}
int main(){
    int v,e,cnt=0;
    cin >> v >> e;
    vector <int> adj[v+1];
    vector <bool> visit(v+1);
    while(e--){
        int a,b; cin >>a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1;i<=v;i++){
        if(!visit[i]){
            component(adj,visit,i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}