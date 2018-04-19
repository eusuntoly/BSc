#include <cstdio>
#include <vector>
using namespace std;
int timp = 1, d[100], T[100], low[100], n, m;
vector<int> a[100];
void dfsCV(int rad, int v){
    d[v] = timp;
    ++timp;
    low[v] = d[v];
    vector<int> F;
    for(int i = 0; i < a[v].size(); ++i){
        if(!d[a[v][i]]){
            F.push_back(a[v][i]);
            T[a[v][i]] = v;
            dfsCV(rad, a[v][i]);
            low[v] = min(low[v], low[a[v][i]]);
        }
        else
            if(a[v][i] != T[v])
                low[v] = min(low[v], d[a[v][i]]);
    }
    if(v == rad && F.size() >= 2)
        printf("%d ", v);
    else
        for(int i = 0; i < F.size(); ++i)
            if(low[F[i]] >= d[v] && T[v])
                printf("%d ", v);
}
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
        if(!d[i])
            dfsCV(i, i);
    return 0;
}
