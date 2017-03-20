#include <stdio.h>
#include <queue>
using namespace std;

int N, M, V, A[1001][1001], B[1001][1001];
bool visited1[1001], visited2[1001];
queue <int> q;
 
void dfs(int x) {
    printf("%d ", x + 1);
    visited1[x] = 1;
    for(int i=0; i<N; i++) {
        if(A[x][i] && !visited1[i]) {
            dfs(i);
        }
    }
}
 
int main(){
    scanf("%d %d %d", &N, &M, &V);
    for(int k=0, x, y; k<M; k++){
        scanf("%d %d", &x, &y);
        A[x-1][y-1] = 1;
		A[y-1][x-1] = 1;
		B[x-1][y-1] = 1;
		B[y-1][x-1] = 1;
    }
    dfs(V - 1);
    puts("");
    q.push(V - 1);
	visited2[V-1] = 1;
    while(!q.empty()) {
        int t = q.front(); q.pop();
        printf("%d ", t + 1);
        for(int i=0; i<N; i++) {
            if(B[t][i] && !visited2[i]){          
                q.push(i);
                visited2[i] = 1;
            }
        }
    }
}
