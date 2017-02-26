#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;
int  T, S, N;
vector<P> A;
vector<P>::iterator it;

int binary(int a, int b, int x, int pos){
    int m;
    while(a<=b){
        m = (a+b)/2;
        if( A[m].X == x ){
            return m;
        }
        else if( A[m].X > x ){
            b = m-1;
        } else {
            a = m+1;
        }
    }
    m = (a+b)/2;
    if( A[m].X == x ){
        return m;
    } else {
        return -1;
    }
}

int main(){
    int i, j, x, pos;
    cin>>T;
    for(i=0; i<T; ++i){
        cin>>S;
        cin>>N;
        A.clear();
        for(j=1; j<=N; ++j){
            cin>>x;
            A.pb(mp(x, j));
        }
        sort(A.begin(), A.end());
        for(j=0; j<N; ++j){
            cout<<A[j].X<<" "<<A[j].Y<<endl;
            pos = binary(j,N-1, ( S - A[j].X ) , 0);
            if( pos != -1 ){
                cout<<A[j].Y<<" "<<A[pos].Y<<endl;
                break;
            }
        }
    }
    return 0;
}
