#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
queue<int> Q;
vector<int> v[100];
bool c[100];
int used[100], P, n, m, C;
void drum(int x){
    if(used[x] == -1){
        printf("%d ", x);
        return;
    }
    drum(used[x]);
    printf("%d ", x);
}
int main(){
    scanf("%d", &P);
    freopen("graf.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &C);
    for(int i = 1; i <= C; ++i){
        int x;
        scanf("%d ", &x);
        c[x] = true;
    }
    for(int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    Q.push(P);
    int rez = 0;
    used[P] = -1;
    while(!Q.empty() && !rez){
        int x = Q.front();
        Q.pop();
        for(int i = 0; i < v[x].size(); ++i)
            if(!used[v[x][i]]){
                if(c[v[x][i]]){
                    rez = v[x][i];
                    used[v[x][i]] = x;
                    break;
                }
                else{
                    used[v[x][i]] = x;
                    Q.push(v[x][i]);
                }
            }
    }
    drum(rez);
    printf("\n");
    return 0;
}
