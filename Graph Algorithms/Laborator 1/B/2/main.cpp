#include <cstdio>
#include <queue>
using namespace std;
int n, m, T, v[1001][1001], nr, xx[] = {-1, 0, 1, 0}, yy[] = {0, 1 , 0, -1};
struct nod{
    int d, x, y;
} used[1001][1001], p[101];
queue<nod> Q;
int main(){
    freopen("graf.in", "r", stdin);
    scanf("%d %d %d\n", &n, &m, &T);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            scanf("%d", &v[i][j]);
            if(v[i][j]){
                p[++nr].x = i;
                p[nr].y = j;
                p[nr].d = 0;
                used[i][j].d = -1;
                used[i][j].x = i;
                used[i][j].y = j;
            }
        }
    for(int i = 0; i <= n + 1; ++i)
        used[i][0].d = used[i][m + 1].d = -1;
    for(int i = 0; i <= m + 1; ++i)
        used[0][i].d = used[n + 1][i].d = -1;
    for(int i = 1; i <= nr; ++i)
        Q.push(p[i]);
    while(!Q.empty()){
        nod a = Q.front();
        Q.pop();
        for(int i = 0; i < 4; ++i)
            if(!used[a.x + xx[i]][a.y + yy[i]].d || used[a.x + xx[i]][a.y + yy[i]].d > a.d + 1){
                used[a.x + xx[i]][a.y + yy[i]].d = a.d + 1;
                used[a.x + xx[i]][a.y + yy[i]].x = used[a.x][a.y].x;
                used[a.x + xx[i]][a.y + yy[i]].y = used[a.x][a.y].y;
                nod P;
                P.x = a.x + xx[i];
                P.y = a.y + yy[i];
                P.d = a.d + 1;
                Q.push(P);
            }
    }
    for(int i = 1; i <= T; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
        printf("%d [%d, %d]\n", used[x][y].d, used[x][y].x, used[x][y].y);
    }
    return 0;
}
