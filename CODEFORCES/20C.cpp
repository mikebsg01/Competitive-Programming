
 #include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sz size
#define INF1 1000000000000000LL;
#define INF2 -1
using namespace std;
typedef long long int lli;
typedef pair<lli, int> Node;
int N,M;
int vis[100012]={0};
lli dist[100012];
int prev[100012];
char toChar(int n){
    return ((char)(n+'0'));
}
class Graph {
    vector<Node> A[100012];
public:
    void add(int v, int w, lli c){
        A[v].PB(MP(c,w));
        A[w].PB(MP(c,v));
    }
    void init(){
        int i;
        for(i=0; i<=N; ++i){
            dist[i] = INF1;
            prev[i] = INF2;
        }
    }
    void dijkstra(int node){
        set<Node> Mon;
        set<Node>::iterator it;
        Node a;
        int i;
        int next, d;
        dist[node]=0;
        Mon.insert(MP(0, node));
        while(!Mon.empty()){
            it = Mon.begin();
            a = (*it);
            Mon.erase(MP(a.X, a.Y));
            vis[a.Y]=1;
            for(i=0; i<A[a.Y].sz(); ++i){
                next = A[a.Y][i].Y;
                d = A[a.Y][i].X;
                if(!vis[next] && a.X+d < dist[next] ){
                    dist[next] = dist[a.Y]+d;
                    prev[next] = a.Y;
                    Mon.insert(MP(dist[next], next));
                }
            }
        }
    }
};
void print(int n){
    if(prev[n] != INF2){
        print(prev[n]);
    }
    cout<<n<<" ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i;
    int a,b;
    lli c;
    Graph g;
    cin>>N>>M;
    g.init();
    for(i=0; i<M; ++i){
        cin>>a>>b>>c;
        g.add(a,b,c);
    }
    g.dijkstra(1);
    if(prev[N] == INF2)
        cout<<"-1\n";
    else {
        print(N);
        cout<<"\n";
    }
    return 0;
}