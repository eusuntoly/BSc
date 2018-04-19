#include <cstdio>
using namespace std;
int n, m, v[100][100];
void read(){
    freopen("graf.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    int x, y;
    for(int i = 1; i <= m; ++i){
        scanf("%d %d", &x, &y);
        v[x][y] = 1;
        v[y][x] = 1;
    }
}
void write(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            printf("%d ", v[i][j]);
        printf("\n");
    }
}
int main(){
    read();
    write();
    return 0;
}
