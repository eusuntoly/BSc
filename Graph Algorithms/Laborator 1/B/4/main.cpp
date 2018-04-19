#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int X, Y, n, m, D, dx[7501], dy[7501], num[7501], ap[7501];
vector<int> v[7501];
queue<int> Q;
int main(){
    freopen("graf.in", "r", stdin);
    freopen("graf.out", "w", stdout);
    scanf("%d %d %d %d\n", &n, &m, &X, &Y);
    for(int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    Q.push(X);
    dx[X] = 1;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i = 0; i < v[x].size(); ++i)
            if(!dx[v[x][i]]){
                dx[v[x][i]] = dx[x] + 1;
                Q.push(v[x][i]);
            }
    }
    Q.push(Y);
    dy[Y] = 1;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i = 0; i < v[x].size(); ++i)
            if(!dy[v[x][i]]){
                dy[v[x][i]] = dy[x] + 1;
                Q.push(v[x][i]);
            }
    }
    D = dx[Y];
    int nr = 0;
    for(int i = 1; i <= n; ++i)
        if(dx[i] + dy[i] == D + 1){
            ++ap[dx[i]];
            num[dx[i]] = i;
        }
    vector<int> sol;
    for(int i = 1; i <= n; ++i)
        if(ap[i] == 1)
            ++nr,
            sol.push_back(num[i]);
    sort(sol.begin(), sol.end());
    printf("%d\n", nr);
    for(int i = 0; i < sol.size(); ++i)
            printf("%d ", sol[i]);
    printf("\n");
    return 0;
}
