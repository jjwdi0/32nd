#include<stdio.h>

int T, N, M, coin[23], dp[21000];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=1; i<=N; i++) scanf("%d", coin + i);
		scanf("%d", &M);
		dp[0] = 1;
		for(int i=1; i<=N; i++) for(int j=0; j<=M; j++) dp[j+coin[i]] += dp[j];
		printf("%d\n", dp[M]);
	}
}
