#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> P;

int T;
lli N, K;

P simulation() {
	lli t;
	P p;

	priority_queue<lli> PQ;
	PQ.push(N);

	for (int j = 0; j < K; ++j) {
        	t = PQ.top() - 1; PQ.pop();
                p.X = t / 2; p.Y = t - p.X;
		//cout << "l: " << p.X << " r: " << p.Y << endl;
               	PQ.push(p.X); PQ.push(p.Y);
        }
	return p;
}

int main() {
	P p;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> N >> K;
		p = simulation();
		cout << "Case #" << (i + 1) << ": " << p.Y << " " << p.X << "\n";
	}
	return 0;
}
