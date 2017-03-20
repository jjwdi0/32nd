#include <stdio.h>

int N, M, par[1003], num[1003], ans;
int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void uni(int x, int y) {
	x = find(x), y = find(y);
	par[x] = y;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) par[i] = i;
	for(int i=0, x, y; i<M; i++) {
		scanf("%d %d", &x, &y);
		uni(x, y);
	}
	for(int i=1; i<=N; i++) if(num[find(i)] == 0) {
		num[find(i)]++;
		ans++;
	}
	printf("%d\n", ans);
}
