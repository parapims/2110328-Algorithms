#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,cnt=0; cin >> N;
    vector<vector <int> > v(N);
    vector<bool> visited(N,false);
    vector<int> parent(N,-1);
    for (int i =0;i<N;i++){
        int a,b; cin >> a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    stack <int> s;
    s.push(0);
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        if(visited[temp]==false) {
            visited[temp]=true;
            for(auto e : v[temp]){
                if (visited[e]==false){
                    parent[e]=temp;
                    s.push(e);
                }
                else if(parent[temp]!=e){
                    int t = temp;
                    while (parent[t]!=parent[e]){
                        cnt++;
                        t = parent[t];
                    }
                        
                    
                    break;
                }
            }
        }
    }
    cout << cnt+1;
    return 0;
}