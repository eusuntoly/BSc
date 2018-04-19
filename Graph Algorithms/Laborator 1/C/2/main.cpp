#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[100];
int n, m, s[100], t, ok = 1, u[100];
void DFS(int x, int p){
    for(int i = 0; i < v[x].size() && ok; ++i){
        if(!u[v[x][i]]){
            u[v[x][i]] = true;
            s[++t] = v[x][i];
            DFS(v[x][i], x);
            s[t--] = 0;
            u[v[x][i]] = false;
        }
        else
            if(v[x][i] != p){
                ok = 0;
                for(int j = t; s[j] != v[x][i]; --j)
                    printf("%d ", s[j]);
                printf("%d ", v[x][i]);
            }
    }
}
int main(){
    freopen("graf.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
        v[x].push_back(y);
    }
    for(int i = 1; i <= n && ok; ++i)
        if(!u[i]){
            u[i] = true;
            DFS(i, 0);
            u[i] = false;
        }
    if(ok)
        printf("REALIZABIL\n");
    return 0;
}
