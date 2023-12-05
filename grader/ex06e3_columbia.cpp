#include <bits/stdc++.h>
using namespace std;
int inf = 100000005;
typedef pair<int,pair<int,int> > DP;
vector <vector<int> > Map,shortest;
set <DP> x;
int direct[4][2] ={{-1,0},{1,0},{0,-1},{0,1}};
bool inbound(int r,int c){
    return not(r < 0 or c < 0 or r >= Map.size() or c >= Map[0].size());
}

void dijkstra(){
    shortest[0][0] = 0;
    x.insert(make_pair(0,make_pair(0,0)));

    while(not x.empty()){
        DP now = *x.begin();
        x.erase(x.begin());

        int r=now.second.first,c=now.second.second;

        int athere = shortest[r][c];
        if(now.first>athere) continue;
        for(int i =0;i<4;i++){
            int rr = r+direct[i][0];
            int cc = c+direct[i][1];
            if(not inbound(rr,cc)) continue;
            int better = athere+Map[rr][cc];
            if (shortest[rr][cc]<=better) continue;

            x.erase(DP(shortest[rr][cc],make_pair(rr,cc)));
            shortest[rr][cc]=better;
            x.insert(DP(better,make_pair(rr,cc)));
        }
    }
}

int main(){
    int R,C; cin >> R >> C;
    Map.resize(R);
    shortest.resize(R);
    for(int i =0;i<R;i++){
        Map[i].resize(C);
        shortest[i].resize(C);
        for(int j =0;j<C;j++){
            cin >> Map[i][j];
            shortest[i][j] = inf;
        }
    }
    dijkstra();
    for(int i =0;i<R;i++){
        for(int j = 0;j<C;j++){
            cout << shortest[i][j]<< ' ';
        }
        cout << "\n";
    }
    return 0;
}