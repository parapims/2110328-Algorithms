#include <bits/stdc++.h>
using namespace std;
vector<int> p;
int Findset(int x){
    if(p[x]==-1) return x;
    p[x]=Findset(p[x]);
    return p[x];
}
void Union(int x,int y){
    int s1 = Findset(x);
    int s2 = Findset(y);
    p[s1]=s2;
}
int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    
    int n; cin >>n;
    p.resize(n);
    for(int i=0;i<p.size();i++){
        p[i]=-1;
    }
    vector< pair<int ,pair<int,int> > > v;
    for(int i =0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            int a; cin >> a;
            v.push_back(make_pair(a,make_pair(i,j)));
        }
    }
    sort(v.begin(),v.end());
    vector<int> x;
    for(auto itr = v.begin();itr!=v.end();itr++){
        if(Findset((*itr).second.first)!=Findset((*itr).second.second)){
            Union(Findset((*itr).second.first),Findset((*itr).second.second));
            x.push_back((*itr).first);
        }
    }
    int c =0;
    for(auto e:x) c+=e;
    cout << c;
    return 0;
}