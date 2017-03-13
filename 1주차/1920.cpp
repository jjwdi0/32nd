#include <stdio.h>
#include <map>
using namespace std;

map<int, int> m;
int N, M;

int main() {
	scanf("%d", &N);
	for(int i=0, x; i<N; i++) scanf("%d", &x), m[x] = 1;
	scanf("%d", &M);
	for(int i=0, x; i<M; i++) scanf("%d", &x), printf("%d\n", m[x]);
}
