#include <stdio.h>

int D[303][3], A[303], N;

int max(int x, int y, int z) { return x > y ? (x > z ? x : z) : (y > z ? y : z); }

int f(int x, int y) {
    if(D[x][y]) return D[x][y];
    if(x == 0) return A[0];
    if(x == 1) {
		if(y == 2) return D[x][y] = A[0] + A[1];
    	if(y == 1) return D[x][y] = A[1];
    	return D[x][y] = A[0];
	}
    if(y == 2) return D[x][y] = f(x - 1, 1) + A[x];
    if(y == 1) return D[x][y] = f(x - 1, 0) + A[x];
    return D[x][y] = max(0, f(x - 1, 1), f(x - 1, 2));
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", A+i);
    printf("%d", max(0, f(N - 1, 1), f(N - 1, 2)));
}
