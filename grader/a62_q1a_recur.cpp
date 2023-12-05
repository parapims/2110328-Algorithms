#include <bits/stdc++.h>
using namespace std;
void recurMatrix(vector<vector<int> > &v,int a,int b,int left,int right,int top,int bottom){
    int s = pow(2,a-1);
    if (a==0){
        v[top][left] = b;
        return;
    }
    recurMatrix(v,a-1,b,left,left+s,top,top+s);
    recurMatrix(v,a-1,b-1,left+s,right,top,top+s);
    recurMatrix(v,a-1,b+1,left,left+s,top+s,bottom);
    recurMatrix(v,a-1,b,left+s,right,top+s,bottom);
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    
    int a,b; cin >> a >> b;
    int s = pow(2,a);
    vector<vector<int> > v(s,vector<int>(s,0));
    recurMatrix(v,a,b,0,s-1,0,s-1);
    for(int i = 0;i<s;i++){
        for(int j =0;j<s;j++){
            cout << v[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}