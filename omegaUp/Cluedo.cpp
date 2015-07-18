#include "cluedo.h"

void ResolverCaso() {
	int A[] = {0, 1, 1, 1 }, c;
	while(c = Teoria(A[1], A[2], A[3])){
        ++A[c];
	}
}
