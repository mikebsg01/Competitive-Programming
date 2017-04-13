#include <iostream>
#include <cstdio>
#include <queue>
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 1005
using namespace std;

int T, N;
int ans;
int M;
priority_queue<int> Q;

void busqueda(){
    int i, mayor;
    for(i=1; i<M; ++i){
        mayor = Q.top();
        Q.pop();
        Q.push(mayor/2); Q.push(mayor-(mayor/2));
        //cout<<ans<<" "<<i+Q.top()<<endl;
        ans = min(ans, i+Q.top());
    }
}

int main(){
    optimize
    //freopen("B-small-attempt2.in","rt",stdin);
    //freopen("B-small-attempt2.out","wt",stdout);
    int i, j, P;
    cin>>T;
    for(i=1; i<=T; ++i){
        cin>>N;
        ans = M = 0;
        Q = priority_queue <int>();
        for(j=0; j<N; ++j){
            cin>>P;
            Q.push(P);
            M = max(M, P);
        }
        ans = M;
        //cout<<">: "<<ans<<endl;
        busqueda();
        cout<<"Case #"<<i<<": "<<ans<<"\n";
    }
    return 0;
}
