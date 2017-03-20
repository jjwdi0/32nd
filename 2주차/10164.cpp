#import <stdio.h>

int D[35][35], N, M, K, xpos, ypos;

int f(int x, int y) {
	if(D[x][y]) return D[x][y];
	if(x == y || y == 0) return D[x][y] = 1;
	return D[x][y] = f(x - 1, y - 1) + f(x - 1, y);
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	K = !!K;
	xpos = (K - 1) / M;
	ypos = (K - 1) % M;
	printf("%d", f(xpos + ypos, xpos) * f(N - 1 - xpos + M - 1 - ypos, N - 1 - xpos));
}
