#include <cstdio>
#include <cmath>

int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.3f\n", hypot(a, b));
	return 0;
}
