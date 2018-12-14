#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int C,R,N;
string S;
vector<char> A;
char T[32][32];
int main(){
    T['i']['j'] = T['j']['i'] = 'k';
    T['i']['k'] = T['k']['i'] = 'j';
    T['j']['k'] = T['k']['j'] = 'i';
    T['i']['i'] = 'i';
    T['j']['j'] = 'j';
    T['k']['k'] = 'k';
    int i, j, M;
    string tmp;
    char P;
    string resp = "ijk"; int q; int next;
    cin>>C;
    for(i=1; i<=C; ++i){
        cin>>N>>R;
        cin>>S;
        tmp = S;
        for(j=1; j<R; ++j){
            S += tmp;
        }
        M = (N*R);
        if(M<3){
            cout<<"Case #"<<i<<": NO\n";
        } else if(M == 3){
            if( S[0] == 'i' && S[1] == 'j' && S[2] == 'k' ){
                cout<<"Case #"<<i<<": YES\n";
            } else {
                cout<<"Case #"<<i<<": NO\n";
            }
        } else {
            q = 0; next = 0;
            for(j=0; j<M; ++j){
                if( next ){
                    P = T[P][S[j]];
                    if( P == resp[q] && q!=2 ){
                        cout<<" <- "<<P;
                        ++q;
                        next = 0;
                        cout<<endl;
                    } else if( q == 2 && P == resp[q] && j == (M-1) ){
                        next = 0;
                        cout<<" <- "<<P;
                        cout<<" <-"<<endl;
                    }
                } else {
                    P = S[j];
                    next = 1;
                }
                cout<<P;
            }
            cout<<endl;
        }
    }
    return 0;
}
