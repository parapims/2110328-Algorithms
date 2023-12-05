#include <bits/stdc++.h>
using namespace std;
int n,k;
string check;
void consec(string ans,int len,int chosen){
    if (len<n){
        if(chosen<n-k){
            consec(ans+"0",len+1,chosen+1);
        }
        consec(ans+"1",len+1,chosen);
    }else{
        size_t found = ans.find(check);
        if (found != string::npos) cout << ans<<endl;
    }
}
int main(){
    cin >> n >> k;
    string x = "";
    for(int i =0;i<k;i++){
        check +="1";
    }
    consec(x,0,0);
    return 0;
}