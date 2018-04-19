#include <cstdio>
#include <queue>
using namespace std;
int n, m, R[102][102], J[102][102], a ,b, maxi = 0x3f3f3f, ar, br, aj, bj, xx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, yy[] = {0, 1, 1, 1, 0, -1, -1, -1};
queue< pair<int, int> > Q;
char s[102][102];
int main(){
    freopen("rj.in", "r", stdin);
    freopen("rj.out", "w", stdout);
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; ++i)
        gets(s[i]);
    char c;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            c = s[i][j - 1];
            if(c == 'X'){
                R[i][j] = -1;
                J[i][j] = -2;
            }
            else
                if(c == 'R'){
                    ar = i;
                    br = j;
                    R[i][j] = 1;
                }
                else
                    if(c == 'J'){
                        aj = i;
                        bj = j;
                        J[i][j] = 1;
                    }
        }
    }
    for(int i = 0; i <= n + 1; ++i)
        R[i][0] = R[i][m + 1] = -1,
        J[i][0] = J[i][m + 1] = -2;
    for(int i = 0; i <= m + 1; ++i)
        R[0][i] = R[n + 1][i] = -1,
        J[0][i] = J[n + 1][i] = -2;
    Q.push( make_pair(ar, br) );
    while(!Q.empty()){
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 8; ++i)
            if(!R[x + xx[i]][y + yy[i]]){
                R[x + xx[i]][y + yy[i]] = R[x][y] + 1;
                Q.push( make_pair(x + xx[i], y + yy[i]) );
            }
    }
    Q.push( make_pair(aj, bj) );
    while(!Q.empty()){
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 8; ++i)
            if(!J[x + xx[i]][y + yy[i]]){
                J[x + xx[i]][y + yy[i]] = J[x][y] + 1;
                Q.push( make_pair(x + xx[i], y + yy[i]) );
            }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(R[i][j] == J[i][j] && R[i][j] < maxi && R[i][j]){
                maxi = R[i][j];
                a = i;
                b = j;
            }
    /*for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)
            printf("%3d ", R[i][j]);
        printf("\n");
    }*/
    printf("%d %d %d\n", maxi, a, b);
    return 0;
}
