#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> m1;
string m2[100005];
string t;
char r[25];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) {
        scanf("%s", r);
        t = "";
        for(int j=0; j<strlen(r); j++) t = t + r[j];
        m1[t] = i;
        m2[i] = t;
    }
    for(int i=1; i<=m; i++) {
        scanf("%s", r);
        if(r[0] <= '9' && r[0] >= '0') {
            int x = 0;
            for(int i=0; i<strlen(r); i++) x = x * 10 + r[i] - '0';
            string ans = m2[x];
            for(int i=0; i<ans.length(); i++) printf("%c", ans.at(i));
            puts("");
        }
        else {
        	t = "";
        	for(int i=0; i<strlen(r); i++) t = t + r[i];
            printf("%d\n", m1[t]);
        }
    }
}
