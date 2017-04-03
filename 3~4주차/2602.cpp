#include <cstdio>

char A[101], B[101], C[101];
int D[101][2], N;

int main() {
	scanf("%s %s %s", A, B, C);
	for(N=0; A[N]; N++);
	D[0][0] = D[0][1] = 1;
	for(int i=0; B[i]; i++) for(int j=N-1; j>=0; j--) {
		if(B[i] == A[j]) D[j + 1][1] += D[j][0];
		if(C[i] == A[j]) D[j + 1][0] += D[j][1];
	}
	printf("%d", D[N][0] + D[N][1]);
}
