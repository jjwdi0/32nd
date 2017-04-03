#include <stdio.h>

int N, t;
long long d[2][21], sum;

int main() {
	scanf("%d %d", &N, &t);
	d[1][t] = 1;
	for (int n = 2; n < N; n++) {
		scanf("%d", &t);
		for (int m = 0; m <= 20; m++,sum=0) {
			if (m + t <= 20) sum += d[(n - 1) & 1][m + t];
			if (m - t >= 0) sum += d[(n - 1) & 1][m - t];
			d[n & 1][m] = sum;
		}	
	}
	scanf("%d", &t);
	printf("%lld\n", d[(N - 1)%2][t]);
}
