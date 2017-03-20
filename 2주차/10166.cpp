#include <stdio.h>
#include <math.h>

int a, b, gcd1, cnt, det[2005][2005];
int min(int x, int y) { return x > y ? y : x; }
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
    scanf("%d %d", &a, &b);
    for(int i=a; i<=b; i++) for(int j=1; j<=i; j++) {
		gcd1 = gcd(j, i);
    	det[j/gcd1][i/gcd1]++;
	}
    for(int i=0; i<=b; i++) for(int j=0; j<=b; j++) if(det[i][j]) cnt++;
    printf("%d\n", cnt);
}
