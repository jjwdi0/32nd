#include <stdio.h>
#define MAX_N 16
#define INF 987654321

int min(int X, int Y) { return X>Y?Y:X; }
int D[MAX_N+1][1<<(MAX_N+1)], n, w[MAX_N+1][MAX_N+1];

int f(int edge, int visited) {
	if(D[edge][visited]) return D[edge][visited];
	if(visited == (1 << n) - 1) {
		if(w[edge][1]) return D[edge][visited] = w[edge][1];
		return INF;
	}
	int ans = INF;
	for(int k=1; k<=n; k++) {
		if(visited & (1 << (k - 1)) || !w[edge][k]) continue;
		ans = min(ans, w[edge][k] + f(k, visited + (1 << (k - 1))));
	}
	return D[edge][visited] = ans;
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%d", &w[i][j]);
	printf("%d", f(1, 1));
}
