#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
void permu (vector<int> &sol,int len,vector<bool> &used,vector<int> a){
    if(len<n){
        for(int i =0;i<n;i++){
            //จะไม่เอาร i มาใส่ถ้าตัวก่อนหน้ายังไม่มี
            if(used[i]==false && used[a[i]]==true){
                used[i] = true;
                sol[len] = i;
                permu(sol,len+1,used,a);
                used[i] = false;
            }
        }
    }else{
        for (auto &e : sol) cout << e << ' ';
        cout << "\n";
    }

}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int m; cin >> n >> m;
    vector<int> a(21,n);
    while(m--){
        int x,y; cin >>x >> y;
        a[y] = x;
    }
    vector<int> sol(n);
    vector<bool> use(n+1);
    use[n]=true;
    permu(sol,0,use,a);
    return 0;
}