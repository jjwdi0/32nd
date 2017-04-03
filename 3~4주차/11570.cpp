#include <stdio.h>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, A[2005], D[2005][2005];

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) D[i][j] = INF;
	D[1][0] = D[0][1] = 0;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
		if(D[i][j] - INF && i - j) {
			if(i > j) {
				D[i+1][j] = min(D[i+1][j], D[i][j] + abs(A[i-1] - A[i]));
				if(j > 0) D[i][i+1] = min(D[i][i+1], D[i][j] + abs(A[j-1] - A[i]));
				else D[i][i+1] = min(D[i][i+1], D[i][j]);
			}
			else {
				D[i][j+1] = min(D[i][j+1], D[i][j] + abs(A[j-1] - A[j]));
				if(i > 0) D[j+1][j] = min(D[j+1][j], D[i][j] + abs(A[i-1] - A[j]));
				else D[j+1][j] = min(D[j+1][j], D[i][j]);
			}
		}
	}
	int ans = INF;
	for(int i=0; i<N; i++) ans = min({ans, D[N][i], D[i][N]});
	printf("%d", ans);
}
