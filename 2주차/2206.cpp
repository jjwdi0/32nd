#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, A[1111][1111], D[1111][1111][2], d[4][2]={1, 0, -1, 0, 0, 1, 0, -1};
queue<pair<pair<int, int>, pair<int, int>>> q;
bool get(int x, int y) { return (x < 0 || y < 0 || x >= N || y >= M); }

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%1d", &A[i][j]);
	q.push({{0, 0}, {0, 0}});
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) D[i][j][0] = D[i][j][1] = INF;
	while(!q.empty()) {
		int x1 = q.front().first.first, y1 = q.front().first.second, x = q.front().second.first, y = q.front().second.second; q.pop();
		if(D[x][y][x1] < y1) continue;
		D[x][y][x1] = y1;
		if(x == N - 1 && y == M - 1) return printf("%d", y1 + 1),0;
		for(int i=0; i<4; i++) {
			int xx = x + d[i][0], yy = y + d[i][1];
			if(get(xx, yy)) continue;
			if(A[xx][yy] && !x1 && D[xx][yy][1] > y1 + 1) D[xx][yy][1] = y1 + 1, q.push({{1, y1 + 1}, {xx, yy}});
			if(!A[xx][yy] && D[xx][yy][x1] > y1 + 1) D[xx][yy][x1] = y1 + 1, q.push({{x1, y1 + 1}, {xx, yy}});
		}
	}
	puts("-1");
}
