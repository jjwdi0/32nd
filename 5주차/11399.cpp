#include <stdio.h>
#include <algorithm>
using namespace std;

int A[1003], N, ans;

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", A + i);
	sort(A, A + N);
	for(int i=0; i<N; i++) cnt += (N - i) * a[i];
	printf("%d", cnt);
}
