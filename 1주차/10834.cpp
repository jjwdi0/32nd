#include <cstdio>

int A, B, C, k = 1, d, N;

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d %d %d", &A, &B, &C);
		k = k * B / A;
		d += C;
	}
	printf("%d %d", d % 2, k);
}
