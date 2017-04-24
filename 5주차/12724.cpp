#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[805], B[805];
int N, T;

int main() {
    scanf("%d", &T);
    for(int c = 1; c <= T; c++) {
        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%lld", A+i);
        for(int i=0; i<N; i++) scanf("%lld", B+i);
        sort(A, A+N);
        sort(B, B+N, greater<ll>());
        ll ans = 0LL;
        for(int i=0; i<N; i++) ans += A[i] * B[i];
        printf("Case #%d: %lld\n", c, ans);
    }
}
