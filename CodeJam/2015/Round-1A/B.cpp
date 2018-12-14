#include <bits/stdc++.h>
#define mp make_pair
#define sz size
#define X first
#define Y second
#define pb push_back
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef pair<int, int> P;

int T,B,N;
vector<P> A;
vector<P> C;
int main(){
    //optimize_ios
    int i, j, k, x;
    int mayor = 0, menor = 0;
    bool solution; P t;
    cin>>T;
    for(i=1; i<=T; ++i){
        cin>>B>>N;
        mayor = 0;
        A.clear(); C.clear();
        for(j=0; j<B; ++j){
            cin>>x;
            A.pb(mp(x, j+1));
            mayor = max(mayor, x);
        }
        sort(A.begin(), A.end());
        for(j=1; j<=mayor; ++j){
            menor = B+1;
            solution = false;
            for(k=0; k<A.sz(); ++k){
                if( (j%A[k].X) == 0 && j>=A[k].X ){
                    if( A[k].Y < menor ){
                        menor = A[k].Y;
                        t = A[k];
                    }
                    solution = true;
                }
            }
            if( solution ){
                C.pb(t);
            }
        }
        int idx = ( (N-1) % (C.sz()) );
        cout<<"Case #"<<i<<": "<<C[idx].Y<<"\n";
    }
    return 0;
}
