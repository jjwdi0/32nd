#import <stdio.h>
#import <algorithm>
#import <queue>
using namespace std;

struct data{ int xpos, ypos, length; } t;
queue <data> q;
int A[103][103], N, M, D[103][103];

int getnum(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= m) return 0;
	return A[x][y];
}

int main() {
	for(int i=0; i<103; i++) for(int j=0; j<103; j++) D[i][j] = 2e9;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%1d", &A[i][j]);
	q.push({0, 0, 1});
	while(!q.empty()) {
		t = q.front(); q.pop();
		if(t.length < D[t.xpos][t.ypos]) D[t.xpos][t.ypos] = t.length;
		else continue;
		if(getnum(t.xpos - 1, t.ypos)) q.push({t.xpos - 1, t.ypos, t.length + 1});
		if(getnum(t.xpos + 1, t.ypos)) q.push({t.xpos + 1, t.ypos, t.length + 1});
		if(getnum(t.xpos, t.ypos - 1)) q.push({t.xpos, t.ypos - 1, t.length + 1});
		if(getnum(t.xpos, t.ypos + 1)) q.push({t.xpos, t.ypos + 1, t.length + 1});
	}
	printf("%d", D[N-1][M-1]);
}
