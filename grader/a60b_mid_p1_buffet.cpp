#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    
    int f,w,n;
    cin >> f >> w >> n;
    vector<bool> food(n+1,false);
    while(f--){
        int a; cin>>a;
        food[a]=true;
    }
    int cnt=0,itr=(2*w);
    for(int i = 1;i<=n;){
        if(food[i]==true){
            cnt++;
            for(int j = i;j<=i+itr;j++){
                food[j]=false;
            }
            i+=itr;
        }
        i++;

    }
    cout << cnt;
    return 0;
}