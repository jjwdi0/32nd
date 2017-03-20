#include <stdio.h>
int A[103][103], N, M, chk[103][103], cnt, mi;

int max(int x, int y) { return x > y ? x : y; }
int get(int x, int y) {
	if(x < 0 || y < 0 || x >= N || y >= N) return -1;
	if(chk[x][y] == 1) return -1;
	return A[x][y];
}

void f(int x, int y) {
	chk[x][y] = 1;
	if(get(x + 1, y) > 0) f(x + 1, y);
	if(get(x, y - 1) > 0) f(x, y - 1);
	if(get(x, y + 1) > 0) f(x, y + 1);
	if(get(x - 1, y) > 0) f(x - 1, y);
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N*N; M = max(A[i/N][i%N], M), i++) scanf("%d", &A[i/N][i%N]);
	M--;
	while(M--) {
		for(int i=0; i<N*N; i++) {
			A[i/N][i%N]--;
			chk[i/N][i%N] = 0;
		}
		
		for(int i=0; i<N*N; i++) {
			if(chk[i/N][i%N] == 0 && A[i/N][i%N] > 0) f(i / N, i % N), cnt++;
		}
		mi = max(cnt, mi);
		cnt = 0;
	}
	if(mi == 0) mi++;
	printf("%d", mi);
}
