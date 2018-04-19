#include <cstdio>
#include <vector>
using namespace std;
int timp = 1, d[100], T[100], low[100], n, m;
vector<int> a[100];
void dfsB(int v){
    d[v] = timp;
    ++timp;
    low[v] = d[v];
    for(int i = 0; i < a[v].size(); ++i){
        if(!d[a[v][i]]){
            T[a[v][i]] = v;
            dfsB(a[v][i]);
            low[v] = min(low[v], low[a[v][i]]);
            if(low[a[v][i]] > d[v])
                printf("%d %d\n", v, a[v][i]);
        }
        else
            if(a[v][i] != T[v])
                low[v] = min(low[v], d[a[v][i]]);
    }
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
            dfsB(i);
    return 0;
}
