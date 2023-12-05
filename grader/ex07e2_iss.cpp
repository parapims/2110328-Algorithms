#include <bits/stdc++.h>
using namespace std;
int n,cnt = 0;
void recur(int sum,int i){
    if (sum==n) cnt++;
    if(sum<n){
        for (int j =i;j<=n;j++){
            recur(sum+j,j);
        }
    }
    return;
}
int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    cin >> n;
    int sum = 0;
    recur(sum,1);
    cout << cnt;
    return 0;
}