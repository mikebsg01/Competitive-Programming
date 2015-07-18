#include <iostream>
using namespace std;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
    int n,m,k,V=0,H=0;
    int i,j,x;
    cin >> n >> m;
    int matriz[n][m];

    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            cin >> matriz[i][j];
        }
    }
    cin >> k;
    char vuelta[k];
    for(x=0;x<k;++x){
            cin >> vuelta[x];
            if(vuelta[x]=='V'){
                V++;
            }
            else if(vuelta[x]=='H'){
                H++;
            }
    }
    if(H%2!=0&&V%2==0){
        for(i=0;i<n;++i){
            for(j=m-1;j>=0;--j){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if(H%2==0&&V%2!=0){
        for(i=n-1;i>=0;--i){
            for(j=0;j<m;++j){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if(H%2!=0&&V%2!=0){
        for(i=n-1;i>=0;--i){
            for(j=m-1;j>=0;--j){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
       for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                cout << matriz[i][j] << " ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
