#import <stdio.h>
#import <algorithm>
using namespace std;

struct data{ int x, y; } T[100003];
int N;
bool cmp(data a, data b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d %d", &T[i].x, &T[i].y);
	sort(T, T+N, cmp);
	for(int i=0; i<N; i++) printf("%d %d\n", T[i].x, T[i].y);
}
