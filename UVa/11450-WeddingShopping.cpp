#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define FOR(t,i,a,b) for (t i = a; i < b; ++i)
#define RFOR(t,i,a,b) for (t i = a; i > b; --i)
#define ITFOR(t,i,a,b) for (t i = a; i != b; ++i)
#define INS(s,x) s.insert(x)
#define ERASE(s,x) s.erase(x)
#define PUSH(s,x) s.push(x)
#define PB(s,x) s.push_back(x)
#define SZ size()
#define MAXM 202
#define MAXC 22
#define INF 202
using namespace std;
typedef vector<int> vectori;
typedef stack<int> stacki;
typedef set<int> seti;

int N, M, C, DP[MAXM][MAXM], ans;
seti A[MAXC];

void init() {
    FOR(int, i, 0, MAXM)  {
        FOR(int, j, 0, MAXM) {
            DP[i][j] = INF;
        }
    }
}

int TopDown(int m, int c) {
    if (m < 0 or (m == 0 and c != C)) {
        return INF;
    } else if (c == C) {
        return DP[m][c] = m;
    } else if (DP[m][c] != INF) {
        return DP[m][c];
    }

    int best = INF, result;

    ITFOR(seti::iterator, it, A[c].begin(), A[c].end()) {
        result = TopDown(m - (*it), c + 1);

        if (result == INF) {
            break;
        }

        best = min(best, result);
    }

    return DP[m][c] = best;
}

int completeSearchWithPruning() {
    int result;
    seti sums, tmp;

    ITFOR(seti::iterator, iti, A[0].begin(), A[0].end()) {
        INS(sums, (*iti));
    }
    
    FOR(int, i, 1, C) {
        tmp.clear();

        ITFOR(seti::iterator, iti, sums.begin(), sums.end()) {
            ITFOR(seti::iterator, itj, A[i].begin(), A[i].end()) {
                result = (*iti) + (*itj);

                if (result > M) {
                    break;
                }

                INS(tmp, result);
            }
        }

        sums.clear();
        sums = seti(tmp);
    }

    return *sums.rbegin();
}


void printSolution() {
    int row = C - 1, column;
    stacki models;

    FOR(int, i, 0, M + 1) {
        if (DP[row][i] != INF) {
            column = i;
            PUSH(models, DP[row][i]);
            break;
        }
    }

    RFOR(int, i, row - 1, -1) {
        column = column + models.top();
        PUSH(models, DP[i][column]);
    }

    cout << "\nSolution: ";

    while (! models.empty()) {
        cout << models.top() << ' ';
        models.pop();
    }

    cout << "\n\n";
}

int bottomUp() {
    int result;

    ITFOR(seti::iterator, it, A[0].begin(), A[0].end()) {
        result = M - (*it);

        if (result >= 0)
            DP[0][result] = (*it);
    }

    FOR(int, i, 1, C) {
        FOR(int, j, 0, M + 1) {
            if (DP[i - 1][j] != INF) {
                ITFOR(seti::iterator, it, A[i].begin(), A[i].end()) {
                    result = j - (*it);

                    if (result >= 0)
                        DP[i][result] = (*it); 
                }
            }
        }
    }

    FOR(int, i, 0, M + 1) {
        if (DP[C - 1][i] != INF) {
            /* printSolution(); */
            return i;
        }
    }

    return INF;
}

int main() {
    optimize_io
    int K, x, minSum, cheaper;
    cin >> N;

    FOR(int, t, 0, N) {
        cin >> M >> C;
        init();
        minSum = 0;

        FOR(int, i, 0, C) {
            cin >> K;
            A[i].clear();
            cheaper = INF;

            FOR(int, j, 0, K) {
                cin >> x;
                INS(A[i], x);
                cheaper = min(cheaper, x);
            }

            minSum += cheaper;
        }

        if (minSum > M) {
            cout << "no solution\n";
        } else {
            /* cout << (M - TopDown(M, 0)) << '\n'; */
            /* cout << completeSearchWithPruning() << '\n'; */
            cout << (M - bottomUp()) << '\n';
        }
    }
    return 0;
}