#include <bits/stdc++.h>
#define mp make_pair
#define sz size
#define X first
#define Y second
#define pb push_back
#define optimize_ios ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef pair<long long int, long long int> P;

int T,B;
long long int N;
vector<P> A;
vector<P> BT;
vector<P> C;
int main(){
    //freopen("B-small-practice.in", "rt", stdin);
    //freopen("B-small-practice.out", "wt", stdout);
    optimize_ios
    int i, j, k, x;
    int mayor = 0, menor = 0;
    bool solution; P t;
    cin>>T;
    for(i=1; i<=T; ++i){
        cin>>B>>N;
        mayor = 0;
        A.clear(); BT.clear(); C.clear();
        for(j=0; j<B; ++j){
            cin>>x;
            A.pb(mp(x, j+1));
            mayor = max(mayor, x);
        }
        sort(A.begin(), A.end());
        for(j=0; j<=mayor; ++j){
            menor = B+1;
            solution = false;
            if( !j || j == mayor ){
                BT.clear();
                for(k=0; k<A.sz(); ++k){
                    if( !j || (j%A[k].X) == 0 ){
                        BT.pb(mp(A[k].Y, A[k].X));
                    }
                }
                sort(BT.begin(), BT.end());
                for(k=0; k<BT.sz(); ++k){
                    C.pb(mp(BT[k].Y, BT[k].X));
                }
            } else {
                for(k=0; k<A.sz(); ++k){
                    if( (j%A[k].X) == 0 ){
                        C.pb(A[k]);
                    }
                }
            }
        }
        /*
        for(k=0; k<C.sz(); ++k){
            cout<<C[k].X<<" "<<C[k].Y<<endl;
        }  */
        int idx = ( ( N - 1 ) % ( C.sz() ) );
        cout<<"Case #"<<i<<": "<<C[idx%C.sz()].Y<<"\n";
    }
    return 0;
}
