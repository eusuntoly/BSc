#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m, Ts[100], Tf[100], parent[100], d[100], used[100];
vector<int> v[100];
void DFS(int p){
    if(!Ts[p]){
        printf("%d ", p);
        return;
    }
    DFS(parent[p]);
    printf("%d ", p);
}
int main(){
    freopen("activitati.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d ", &d[i]);
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        used[y] = true;
    }
    queue<int> Q;
    for(int i = 1; i <= n; ++i)
        if(!used[i])
            Q.push(i);
    int maxi = 0, p;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        Tf[x] = Ts[x] + d[x];
        if(Tf[x] > maxi)
            maxi = Tf[x],
            p = x;
        for(int i = 0; i < v[x].size(); ++i)
            if(Tf[x] > Ts[v[x][i]]){
                Ts[v[x][i]] = Tf[x];
                parent[v[x][i]] = x;
                Q.push(v[x][i]);
            }
    }
    printf("Timpul minim %d\n", maxi);
    printf("Activitati critice: ");
    DFS(p);
    printf("\n");
    for(int i = 1; i <= n; ++i)
        printf("%d: %d %d\n", i, Ts[i], Tf[i]);
    return 0;
}
