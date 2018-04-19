#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, color[100], S, T, parent[100], used[100], C[100][100], F[100][100];
vector<int> a[100];
vector<int> v[100];
vector<int> w[100];
bool build_range(){
    memset(parent, 0, sizeof(parent));
    memset(used, 0, sizeof(used));
    queue<int> Q;
    Q.push(S);
    used[S] = true;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i = 0; i < v[x].size(); ++i)
            if(!used[v[x][i]] && C[x][v[x][i]] - F[x][v[x][i]] > 0){
                Q.push(v[x][i]);
                used[v[x][i]] = true;
                parent[v[x][i]] = x;
                if(v[x][i] == T)
                    return true;
            }
        for(int i = 0; i < w[x].size(); ++i)
            if(!used[w[x][i]] && F[w[x][i]][x]){
                Q.push(w[x][i]);
                used[w[x][i]] = true;
                parent[w[x][i]] = -x;
                if(w[x][i] == T)
                    return true;
            }
    }
    return false;
}
void revise_range(){
    int x = T, mini = 0x3f3f3f3f;
    while(x != S)
        if(parent[x] < 0){
            mini = min(mini, F[x][-parent[x]]);
            x = -parent[x];
        }
        else{
            mini = min(mini, C[parent[x]][x] - F[parent[x]][x]);
            x = parent[x];
        }
    x = T;
    while(x != S)
        if(parent[x] < 0){
            F[x][-parent[x]] -= mini;
            x = -parent[x];
        }
        else{
            F[parent[x]][x] += mini;
            x = parent[x];
        }
}
int main(){
    freopen("graf.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i <= m; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    color[1] = 1;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i = 0; i < a[x].size(); ++i)
            if(!color[a[x][i]]){
                if(color[x] == 1)
                    color[a[x][i]] = 2;
                else
                    color[a[x][i]] = 1;
                Q.push(a[x][i]);
            }
    }
    for(int i = 1; i <= n; ++i)
        if(color[i] == 1){
            for(int j = 0; j < a[i].size(); ++j){
                v[i].push_back(a[i][j]);
                C[i][a[i][j]] = 1;
            }
            w[i].push_back(n + 1);
            v[n + 1].push_back(i);
            C[n + 1][i] = 1;
        }
        else{
            for(int j = 0; j < a[i].size(); ++j)
                w[i].push_back(a[i][j]);
            v[i].push_back(n + 2);
            w[n + 2].push_back(i);
            C[i][n + 2] = 1;
        }
    S = n + 1;
    T = n + 2;
    while(build_range())
        revise_range();
    for(int i = 0; i < v[S].size(); ++i)
        for(int j = 0; j < v[v[S][i]].size(); ++j)
            if(F[v[S][i]][v[v[S][i]][j]])
                printf("%d %d\n", v[S][i], v[v[S][i]][j]);
    return 0;
}
