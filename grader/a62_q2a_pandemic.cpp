#include <bits/stdc++.h>
using namespace std;
bool inbound(int r,int c,vector<vector<int> > &v){
    return not(r < 0 or c < 0 or r >= v.size() or c >= v[0].size());
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,c,T; cin >>r>>c>>T;
    vector<vector<int> > v(r,(vector<int>(c,0)));
    queue<pair<int,int> > q;
    vector<int>t(T+1,0);
    int direct[4][2] ={{-1,0},{1,0},{0,-1},{0,1}};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> v[i][j];
            if (v[i][j]==1) {
                q.push(make_pair(i,j));
                t[0]++;
            }
        }
    }
    for(int i =0;i<T;i++){
        for(int j =0;j<t[i];j++){
            pair<int,int> temp = q.front();
            q.pop();
            int r = temp.first,c=temp.second;
            for(int j =0;j<4;j++){
                int rr = r+direct[j][0];
                int cc = c+direct[j][1];
                if(not inbound(rr,cc,v)) continue;
                if (v[rr][cc]==0){
                    v[rr][cc]=1;
                    t[i+1]++;
                    q.push(make_pair(rr,cc));
                }
            }
        }
    }
    int sum = 0;
    for(auto e :t) sum+=e;
    cout << sum << "\n";
    return 0;
}