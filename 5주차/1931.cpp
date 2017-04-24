#include<cstdio>
#include<algorithm>
using namespace std;

int N, R, E;
pair<int, int> T[100005];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d %d", &T[i].second, &T[i].first);
    sort(T, T + N);
    for (int i=0; i<N; i++) if(T[i].second >= E) E = T[i].first, R++;
    printf("%d\n", R);
}
