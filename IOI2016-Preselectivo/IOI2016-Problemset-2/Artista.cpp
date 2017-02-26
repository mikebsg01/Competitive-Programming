#include <bits/stdc++.h>
#define optimize_ios(x) ios_base::sync_with_stdio(x);cin.tie(x)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAXN 201
#define MAXK 1001
#define INF -1
using namespace std;
typedef pair<int, int> P;

typedef struct Rec {
    int color;
    P p1, p2, p3, p4;
} Rec;

int N, M;
int G, C;
int K;
int A[MAXK][2]; int idx;
Rec R[MAXK];

bool dentro(int y, int x, int i){
    /*
    cout<<R[i].p1.Y<<" - "<<R[i].p1.X<<", ";
    cout<<R[i].p2.Y<<" - "<<R[i].p2.X<<", ";
    cout<<R[i].p3.Y<<" - "<<R[i].p3.X<<", ";
    cout<<R[i].p4.Y<<" - "<<R[i].p4.X<<endl;
    cout<<"==================="<<R[i].color<<endl;
    */
    if( y >= R[i].p1.Y && x >= R[i].p1.X &&
        y >= R[i].p2.Y && x <= R[i].p2.X &&
        y <= R[i].p3.Y && x >= R[i].p3.X &&
        y <= R[i].p4.Y && x <= R[i].p4.X ) {
        //cout<<"***Entro!! "<<y<<" "<<x<<" -> "<<endl;
        return true;
    }
    return false;
}

int main(){
    optimize_ios(0);
    int i, j, k;
    int Ci, Ni, Mi, Xi, Yi;
    cin>>M>>N;
    cin>>G>>C;
    cin>>K;
    for(i=0; i<K; ++i){
        cin>>Ci>>Mi>>Ni>>Xi>>Yi;
        R[i].color = Ci;
        R[i].p1.X = Xi;            R[i].p1.Y = Yi;
        R[i].p2.X = Xi + Mi - 1;   R[i].p2.Y = Yi;
        R[i].p3.X = Xi;            R[i].p3.Y = Yi + Ni - 1;
        R[i].p4.X = Xi + Mi - 1;   R[i].p4.Y = Yi + Ni - 1;
    }
    for( i=1; i<=N; ++i ){
        for( j=1; j<=M; ++j ){
            idx = 1;
            A[idx][0] = C;
            A[idx][1] = G;
            for( k = 0; k < K; ++k ){
                if( dentro(i, j, k) ){
                    if( R[k].color == INF ) {
                        if( idx > 0 ){
                            if( A[idx][1] > 1  ) {
                                --A[idx][1];
                            } else {
                                --idx;
                            }
                        }
                    } else {
                        if( R[k].color == A[idx][0] ){
                            ++A[idx][1];
                        } else {
                            ++idx;
                            A[idx][0] = R[k].color;
                            A[idx][1] = 1;
                        }
                    }
                }
            }
            if( idx <= 0 ){
                cout<<"-1 ";
            } else {
                cout<<A[idx][0]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
