#include <stdio.h>
int A[22], N, K, cnt;

void f(int x, int y) {
	if(x == N) {
		if(y == K) cnt++;
		return;
	}
	f(x + 1, y + A[x]);
	f(x + 1, y);
}

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	f(0, 0);
	printf("%d", cnt - !K);
}
