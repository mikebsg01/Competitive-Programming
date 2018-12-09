#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);
#define dd(x) cout << #x << ": " << x << endl;
#define PB(s, x) s.push_back(x)
#define INS(s, x) s.insert(x)
#define ERASE(s, x) s.erase(x)
#define PUSH(s, x) s.push(x)
#define UPPER(s, x) s.upper_bound(x)
#define LOWER(s, x) s.lower_bound(x)
#define MP make_pair
#define ALL(s) s.begin(), s.end()
#define X first
#define Y second
#define X1 first.first
#define Y1 first.second
#define X2 second.first
#define Y2 second.second
#define Line1 first
#define Line2 second.first
#define Line3 second.second
#define MAXN 100
#define EPS numeric_limits<double>::epsilon()
#define NEVER -2
#define INF -1
#define NI false
using namespace std;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<bool> vectorbl;
typedef vector<int> vectori;
typedef vector<lli> vectorlli;
typedef pair<double, double> Point;
typedef pair<Point, Point> Line;
typedef pair<int, pair<int, int> > Tern;
typedef pair<Line, pair<Line, Line> > TernLines;
typedef vector<Tern> vectorTern;
typedef vector<TernLines> vectorTriang;
typedef set<lli> setlli;
typedef map<int, int> mapi;
typedef map<lli, lli> maplli;

int N;
Line L[MAXN];
vectorTriang TR;
//int A[MAXN], B[MAXN], C[MAXN];
vectorTern T;

void pp(int i) {
	cout << "(" << L[i].X1 << "," << L[i].Y1 << ") - (" << L[i].X2 << "," << L[i].Y2 << ")" << endl;
}

void ppt(Line& l) {
	cout << "(" << l.X1 << "," << l.Y1 << ") - (" << l.X2 << "," << l.Y2 << ")" << endl;
}

double getM(Line& l) {
	return (l.Y2 - l.Y1) / (l.X2 - l.X1);
}

double getB(Line& l, double m) {
	return l.Y1 - m * l.X1;
}

inline bool intercept(double m1, double b1, double m2, double b2) {
	double a = b1 - b2; 
	double b = m2 - m1;
	
	if (b == 0) {

		if (b == a) {
			//return INF;
			return false;
		}

		//return NEVER;
		return false;
	}
	return true;
}

bool onSegment(Point p, Point q, Point r) { 
    if (q.X <= max(p.X, r.X) && q.X >= min(p.X, r.X) && 
        q.Y <= max(p.Y, r.Y) && q.Y >= min(p.Y, r.Y)) 
       return true; 
  
    return false; 
} 

int orientation(Point p, Point q, Point r)  { 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.Y - p.Y) * (r.X - q.X) - 
              (q.X - p.X) * (r.Y - q.Y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

bool doIntersect(Point p1, Point q1, Point p2, Point q2) { 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

int main() {
	optimize_io
	int i, j, k, p, q, n, triangles = 0;
	bool f, g, h;
	bool 	fsa, fsb,
		gsa, gsb,
		hsa, hsb;
	double	fa, fb,
		ga, gb,
		ha, hb;
	char o;
	double m[4], b[4];
	//double x[4], y[4];
	//Line t[4];
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> L[i].X1 >> o >> L[i].Y1 >> o >> L[i].X2 >> o >> L[i].Y2;
		//ppt(L[i]);
		/*
		A[i] = L[i].Y2 - L[i].Y1;
		B[i] = -1 * (L[i].X2 - L[i].X1);
		C[i] = ((L[i].Y2 - L[i].Y1) * (-1 * L[i].X1)) - ((L[i].X2 - L[i].X1) * (-1 * L[i].Y1));*/
	}
	//cout << numberOfTringles(A, B, C, N) << endl;
	//cout << endl;

	for (i = 0; i < N; ++i) {
		for (j = i + 1; j < N; ++j) {
			for (k = j + 1; k < N; ++k) {
				//ppt(L[i]); ppt(L[j]); ppt(L[k]);
				m[0] = getM(L[i]);
				b[0] = getB(L[i], m[0]);
				m[1] = getM(L[j]);
 				b[1] = getB(L[j], m[1]);
				m[2] = getM(L[k]);
				b[2] = getB(L[k], m[2]);

				f = intercept(m[0], b[0], m[1], b[1]);
				g = intercept(m[1], b[1], m[2], b[2]);
				h = intercept(m[2], b[2], m[0], b[0]);

				if (f and g and h) {
					for (int z  = 0; z < 3; ++z) {
						cout << m[z] << " ";
					}
					cout << endl;
					cout << i << " " << j << " " << k << endl;
					cout << endl << endl;
					/*
					if (isinf(fa) or isinf(fb)) {
						y[0] = (m[0] * x[0]) + b[0];
					}

					if (isinf(ga) or isinf(gb)) {

					} else {
						y[1] = (m[1] * x[1]) + b[1];
					}

					if (isinf(ha) or isinf(hb)) {

					} else {
						y[2] = (m[2] * x[2]) + b[2];
					}
					
					for (int z = 0; z < 3; ++z) {
						cout << x[0] << " " << y[0] << endl;
					}
					cout << endl;

					t[0] = MP(MP(x[0], y[0]), MP(x[1], y[1]));
					t[1] = MP(MP(x[0], y[0]), MP(x[2], y[2]));
					t[2] = MP(MP(x[1], y[1]), MP(x[2], y[2]));
					PB(TR, MP(t[0], MP(t[1], t[2])));
					*/

					PB(T, MP(i, MP(j, k)));
					++triangles;
				}
			}
		}
	}
	//dd(triangles);

	for (p = 0, n = T.size(); p < n; ++p) {
		//cout << T[p].X << " " << T[p].Y.X << " " << T[p].Y.Y << endl;
		i = T[p].X;
		j = T[p].Y.X;
		k = T[p].Y.Y;
		/*
		t[0] = TR[p].Line1;
		t[1] = TR[p].Line2;
		t[2] = TR[p].Line3;
		*/	

		for (q = 0; q < N; ++q) {
			if (q != i and q != j and q != k) {
				/*
				m[0] = getM(L[i]);
				b[0] = getB(L[i], m[0]);
				m[1] = getM(L[j]);
				b[1] = getB(L[j], m[1]);
				m[2] = getM(L[k]);
				b[2] = getB(L[k], m[2]);
				m[3] = getM(L[q]);
				b[3] = getB(L[q], m[3]);
				*/

				/*
				f = doIntersect(L[i].X, L[i].Y, t[0].X, t[0].Y);
				g = doIntersect(L[j].X, L[j].Y, t[1].X, t[1].Y);
				h = doIntersect(L[k].X, L[k].Y, t[2].X, L[2].Y);
			**/
				f = doIntersect(L[i].X, L[i].Y, L[q].X, L[q].Y);
				g = doIntersect(L[j].X, L[j].Y, L[q].X, L[q].Y);
				h = doIntersect(L[k].X, L[k].Y, L[q].X, L[q].Y);

				if (	(f == true and f == g) or
					(f == true and f == h) or
					(g == true and g == h)) {
					--triangles;
					break;
				}
			}
		}
	}
	cout << triangles << endl;
	return 0;
}
