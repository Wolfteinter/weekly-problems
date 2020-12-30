#include <bits/stdc++.h>
//The solucion is the brutal force solucion
using namespace std;
int main(){
    int n;
    cin >> n;
    bool bandera = false;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i%2 == 0 && j%2 == 0 && i+j == n){
                bandera = true;
                break;
            }
        }
        if(bandera) break;
    }
    if(bandera) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}