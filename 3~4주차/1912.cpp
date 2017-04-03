#include <stdio.h>

int D[100003], A[100003], N, max = -2e9;

int f(int x) {
	if(D[x]) return D[x];
	if(x == 0) return D[x] = A[x];
	if(f(x - 1) < 0) return D[x] = A[x];
	return D[x] = f(x - 1) + A[x];
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=0; i<N; i++) if(max < f(i)) max = f(i);
	printf("%d", max);
}
