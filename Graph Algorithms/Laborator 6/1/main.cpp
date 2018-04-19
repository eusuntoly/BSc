#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, S, T, flux, parent[100], used[100], C[100][100], F[100][100];
vector<int> v[100];
vector<int> w[100];
vector<int> cut;
bool build_range(){
    memset(parent, 0, sizeof(parent));
    memset(used, 0, sizeof(used));
    queue<int> Q;
    cut.clear();
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
        cut.push_back(x);
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
bool is_ok(){
    for(int x = 1; x <= n; ++x)
        if(x != S && x != T){
            int a = 0, b = 0;
            for(int i = 0; i < v[x].size(); ++i){
                if(C[x][v[x][i]] < F[x][v[x][i]])
                    return false;
                a += F[x][v[x][i]];
            }
            for(int i = 0; i < w[x].size(); ++i)
                b += F[w[x][i]][x];
            if(a != b)
                return false;
        }
    return true;
}
int main(){
    freopen("retea.in", "r", stdin);
    scanf("%d %d %d %d", &n, &S, &T, &m);
    for(int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        w[y].push_back(x);
        scanf("%d %d", &C[x][y], &F[x][y]);
    }
    if(is_ok())
        printf("DA\n");
    else
        printf("NU\n");
    while(build_range())
        revise_range();
    for(int i = 0; i < v[S].size(); ++i)
        flux += F[S][v[S][i]];
    printf("%d\n", flux);
    for(int x = 1; x <= n; ++x)
        for(int i = 0; i < v[x].size(); ++i)
            printf("%d %d %d\n", x, v[x][i], F[x][v[x][i]]);
    memset(used, 0, sizeof(used));
    for(int i = 0; i < cut.size(); ++i)
       used[cut[i]] = true;
    int s = 0;
    vector< pair<int, int> > sol;
    for(int i = 0; i < cut.size(); ++i)
        for(int j = 0; j < v[cut[i]].size(); ++j)
            if(!used[v[cut[i]][j]]){
                sol.push_back( make_pair(cut[i], v[cut[i]][j]) );
                s += F[cut[i]][v[cut[i]][j]];
            }
    printf("%d\n", s);
    for(int i = 0; i < sol.size(); ++i)
        printf("%d %d\n", sol[i].first, sol[i].second);
    return 0;
}
