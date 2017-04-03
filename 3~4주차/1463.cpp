#include <bits/stdc++.h>
using namespace std;

int N, D[1000005];

int main() {
	scanf("%d", &N);
	for(int i=2; i<=N; i++) D[i] = min({ D[i / 3] + i % 3 + 1, D[i / 2] + i % 2 + 1, D[i - 1] + 1 });
	printf("%d", D[N]);
}
