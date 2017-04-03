#include <stdio.h>
#define MOD 1000000

int n, dp[1003][3][5];

int main() {
	scanf("%d", &n);
	dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 1;
	for(int i=1; i<n; i++) for(int j=0; j<2; j++) for(int k=0; k<3; k++) {
		dp[i][j][k] %= MOD;
		if(dp[i][j][k]) {
			if(j == 0) {
				if(k == 2) {
					dp[i+1][j][0] += dp[i][j][k];
					dp[i+1][j+1][0] += dp[i][j][k];
				}
				else {
					dp[i+1][j][0] += dp[i][j][k];
					dp[i+1][j+1][0] += dp[i][j][k];
					dp[i+1][j][k+1] += dp[i][j][k];
				}
			}
			else {
				if(k == 2) dp[i+1][j][0] += dp[i][j][k];
				else {
					dp[i+1][j][0] += dp[i][j][k];
					dp[i+1][j][k+1] += dp[i][j][k];
				}
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<2; i++) for(int j=0; j<3; j++) cnt += dp[n][i][j];
	printf("%d", cnt % MOD);
}
