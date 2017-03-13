#include <stdio.h>
#define LIM 10000000

int A[LIM * 2], N, M;

int main() {
	scanf("%d", &N);
	for(int i=0, x; i<N; i++) {
		scanf("%d", &x);
		A[x + LIM] = 1;
	}
	scanf("%d", &M);
	for(int i=0, x; i<M; i++) {
		scanf("%d", &x);
		printf("%d ", A[x + LIM]);
	}
}
