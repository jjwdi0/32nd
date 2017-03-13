#include <stdio.h>
typedef long long ll;

ll A[3] = {0LL, 1LL, 1LL};
int N;

int main() {
	scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        A[2] = A[1] + A[0];
        A[0] = A[1];
		A[1] = A[2];
    }
    printf("%lld\n", A[2] + A[2] + A[0] + A[0]);
}
