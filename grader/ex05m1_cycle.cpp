#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    for(int i =0;i<n;i++){
        int V,e,cnt=0; cin >> V >> e;
        vector<vector<int> > v(V);
        vector<bool> visited(V,false);
        vector<int> from(V,-1);
        if(e==0) {cout << "NO" << "\n"; continue;}
        while(e--){
            int a,b; cin >>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        stack<int> s;
        bool check = false;
        while(cnt<V){
            for(int i =0;i<V;i++){
                if(visited[i]==false){
                    s.push(i);
                }
            }
            while(!s.empty()){
                int temp = s.top();
                s.pop();
                cnt++;
                if(!visited[temp]){
                    visited[temp]=true;
                    for(auto e:v[temp]){
                        if(!visited[e]){
                            from[e]=temp;
                            s.push(e);
                        }
                        else {
                            if(from[temp]!=e) check=true;
                        }
                    }
                }
            }
        }

        if(check) cout << "YES"<<"\n";
        else cout << "NO"<<"\n";
        
    }
    return 0;
}
