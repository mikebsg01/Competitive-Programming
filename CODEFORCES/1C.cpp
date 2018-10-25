#include <bits/stdc++.h>
#define dd(x) cout << #x << ": " << x << endl;
#define NUM_POINTS 3
#define MAXN 100
#define X first
#define Y second
using namespace std;
typedef pair<double, double> pd;

const double PI = 3.141592;
const double epsilon = 1.0e-5;

pd P[NUM_POINTS];
double DIST[NUM_POINTS], ANGLE[NUM_POINTS], sides, circumradius;

inline pd p(int idx) {
	return P[idx % NUM_POINTS];
}

inline double d(int idx) {
	return DIST[idx % NUM_POINTS];
}

inline double internalAngleSum(double n) {
	return (n - 2) * 180;
}

inline double internalAngle(double n) {
	return internalAngleSum(n) / n;
}

inline double fnSin(double x) {
	return sin(x * PI / 180);
}

inline double fnCos(double x) {
	return cos(x * PI / 180);
}

inline double fnTan(double x) {
	return tan(x * PI / 180);
}

inline double dist(double x1, double y1, double x2, double y2) {
	return hypot((x1 - x2), (y1 - y2));
}

double fgcd(double a, double b) {
	return abs(b) < epsilon ? a : fgcd(b, fmod(a, b));
}

inline double diff(double a, double b) {
	return abs(a - b);
}

inline bool isEqual(double a, double b) {
	return diff(a, b) < epsilon;
}

double getAngle(int vertex) {
	double  a = d(vertex + 1),
		b = d(vertex + 2),
		c = d(vertex),
		cos = ((a * a) + (b * b) - (c * c)) / (2 * a * b);
	
	return acos(cos);
}

inline double getSides(double angle) {
	return -360 / (angle - 180);
}

inline double getArea(double n, double r) {
	return (n * r * r * sin((2 * PI) / n)) / 2;
}

void getDistances() {
	for (int i = 0; i < NUM_POINTS; ++i) {
		DIST[i] = dist(p(i).X, p(i).Y, p(i + 1).X, p(i + 1).Y);
	}
}

void getSides() {
	int vertex;
	double gcd;

	for (int i = 0; i < NUM_POINTS; ++i) {
		vertex = (i + 2) % NUM_POINTS;
		ANGLE[i] = getAngle(vertex);
	}

	gcd = fgcd(ANGLE[0] / PI, fgcd(ANGLE[1] / PI, ANGLE[2] / PI));
	sides = 1 / gcd;
}

void getCircumradius() {
	double 	a = DIST[1],
		b = DIST[2],
		c = DIST[0],
		semiperimeter = (a + b + c) / 2,
		triangleArea = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));

	circumradius = (a * b * c) / (4 * triangleArea);
}

int main() {
	for (int i = 0; i < NUM_POINTS; ++i) {
		cin >> P[i].X >> P[i].Y;
	}

	getDistances();
	getSides();
	getCircumradius();
	cout << fixed << setprecision(6) << getArea(sides, circumradius) << '\n';
	return 0;
}
