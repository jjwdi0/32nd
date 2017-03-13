#include <stdio.h>
int N, K, A, B, P;

int main() {
    scanf("%d %d", &P, &K);
    for(int i=0; i<K; i++) {
        scanf("%d %d", &a, &b);
        if(A >= B) puts((A - B) <= (P - B) / 2 + 1 ? "1" : "0");
        else puts((B - A) <= (P - A + 1) / 2 ? "1" : "0");
    }
}
