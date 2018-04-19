#include <stdio.h>
#include <string.h>
#define N 1002
#define M 1002
int v[2][N][M], n, m, K, a, b = 1, xx[] = {- 1, -1, -1, 0, 1, 1, 1, 0}, yy[] = {-1, 0, 1, 1, 1, 0, -1, -1}, max;
char C;
void game(){
    int i, j, k, pop = 0;
    if(C == 'T'){
        if(m > 2)
            for(i = 1; i <= n; ++i)
                v[a][i][0] = v[a][i][m],
                v[a][i][m + 1] = v[a][i][1];
        if(n > 2)
            for(i = 1; i <= m; ++i)
                v[a][0][i] = v[a][n][i],
                v[a][n + 1][i] = v[a][1][i];
        if(n > 2 || m > 2){
            v[a][0][0] = v[a][n][m];
            v[a][0][m + 1] = v[a][n][1];
            v[a][n + 1][0] = v[a][1][m];
            v[a][n + 1][m + 1] = v[a][1][1];
        }
    }
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j){
            int nr = 0;
            for(k = 0; k < 8; ++k)
                if(v[a][i + xx[k]][j + yy[k]]) ++nr;
            if(v[a][i][j]){
                ++pop;
                if(nr < 2 || nr > 3)
                    v[b][i][j] = 0;
                else
                    v[b][i][j] = 1;
            }
            else
                if(nr == 3)
                    v[b][i][j] = 1;
        }
    a ^= 1;
    b ^= 1;
    for(i = 1; i <= n; ++i)
        memset(v[b][i], 0, sizeof(v[b][i]));
    if(pop > max)
        max = pop;
}
int main(){
    freopen("d.in", "r", stdin);
   //  freopen("d.out", "w", stdout);
    scanf("%c %d %d %d", &C, &m, &n, &K);
    int i, j;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
            scanf("%d", &v[a][i][j]);
    for(i = 1; i <= K; ++i) game();
    int pop = 0;
    for(i = 1; i <= n; ++i){
        for(j = 1; j <= m; ++j){
            if(v[a][i][j]) ++pop;
            printf("%d ", v[a][i][j]);
        }
        printf("\n");
    }
    if(pop > max)
        max = pop;
    printf("%.3f%c\n", max * 100.0 / (n * m), '%');
    return 0;
}
