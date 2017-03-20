#include <stdio.h>
#include <algorithm>

int A[27][27], B[500], cnt, N;

void f(int x, int y) {
	A[x][y] = -A[x][y];
	if(x != 0 && A[x-1][y] > 0) B[cnt]++, f(x - 1, y);
	if(y < N && A[x][y+1] > 0) B[cnt]++, f(x, y + 1);
	if(x < N && A[x+1][y] > 0) B[cnt]++, f(x + 1, y);
	if(y != 0 && A[x][y-1] > 0) B[cnt]++, f(x, y - 1);
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N*N; i++) scanf("%1d", &A[i/N][i%N]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(A[i][j] > 0) B[cnt]++, f(i, j), cnt++;
	std::sort(B, B + cnt);
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++) printf("%d\n", B[i]);
}
