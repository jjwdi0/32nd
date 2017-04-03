#include <stdio.h>
#include <string.h>

int lcs[1003][1003];
char a[1003], b[1003];

int max(int x, int y) { return x > y ? x : y; }

int main() {
	scanf("%s\n%s", a, b);
	N = strlen(a), M = strlen(b);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
		if(A[i-1] == B[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
		else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
	}
	printf("%d", lcs[N][M]);
}
