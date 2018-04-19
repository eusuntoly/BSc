#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m, color[100], used[100], parent[100];
bool ok;
vector<int> v[100];
void write(int a, int b){
    ok = false;
    printf("%d ", a);
    while(b != a){
        printf("%d ", b);
        b = parent[b];
    }
    printf("\n");
}
void DFS(int x){
    for(int i = 0; i < v[x].size() && ok; ++i)
        if(!used[v[x][i]]){
            used[v[x][i]] = used[x] + 1;
            parent[v[x][i]] = x;
            DFS(v[x][i]);
        }
        else
            if(v[x][i] != parent[x] && (used[x] - used[v[x][i]]) % 2 == 0)
                write(v[x][i], x);
}
int main(){
    freopen("graf.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i <= m; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    color[1] = 1;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty() && !ok){
        int x = Q.front();
        Q.pop();
        for(int i = 0; i < v[x].size(); ++i)
            if(!color[v[x][i]]){
                if(color[x] == 1)
                    color[v[x][i]] = 2;
                else
                    color[v[x][i]] = 1;
                Q.push(v[x][i]);
            }
            else
                if(color[v[x][i]] == color[x])
                    ok = true;
    }
    if(!ok){
        int nr1 = 0, nr2 = 0;
        for(int i = 1; i <= n; ++i)
            if(color[i] == 1){
                printf("%d ", i);
                ++nr1;
            }
        printf("\n");
        for(int i = 1; i <= n; ++i)
            if(color[i] == 2){
                printf("%d ", i);
                ++nr2;
            }
        if(nr1 *  nr2 == m)
            printf("\nGraf bipartit complet.\n");
        else
            printf("\nGraf bipartit incomplet.\n");
    }
    else{
        used[1] = 1;
        DFS(1);
    }
    return 0;
}
