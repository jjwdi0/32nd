#include <stdio.h>

int D[55][55][55][55], n, m, a[55][55], S[55][55];

int min(int X, int Y) { return X < Y ? X : Y; }

int f(int x, int y, int z, int w) {
	if(D[x][y][z][w]) return D[x][y][z][w];
	if(x == z && y == w) return 0;
	int T = 2e9;
	for(int k=x; k<z; k++) T = min(T, S[z][w] - S[x-1][w] - S[z][y-1] + S[x-1][y-1] + f(x, y, k, w) + f(k + 1, y, z, w));
	for(int k=y; k<w; k++) T = min(T, S[z][w] - S[x-1][w] - S[z][y-1] + S[x-1][y-1] + f(x, y, z, k) + f(x, k + 1, z, w));
	return D[x][y][z][w] = T;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &a[i][j]);
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) S[i][j] = a[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1];
	printf("%d", f(1, 1, n, m));
}
