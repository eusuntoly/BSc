#include <cstdio>
#include <vector>
using namespace std;
int n, a[100];
void solve(){
    vector<int> degree(100, 0);
    for(int i = 1; i <= n; ++i)
        degree[i] = 1;
    for(int i = 1; i < n - 1; ++i)
        degree[i] = degree[i] + 1;
    for(int i = 1; i < n - 1; ++i)
        for(int j = 1; j <= n; ++j)
            if(degree[j] == 1){
                printf("%d %d\n", i, j);
                degree[i] = degree[i] - 1;
                degree[j] = degree[j] - 1;
                break;
            }
    int u = 0, v = 0;
    for(int i = 1; i <= n; ++i)
        if(degree[i] == 1){
            if(u == 0)
                u = i;
            else{
                v = i;
                break;
            }
        }
    printf("%d %d\n", u, v);
    degree[u] = degree[u] - 1;
    degree[v] = degree[v] - 1;
}
int main(){
    freopen("rezultat.out", "r", stdin);
    freopen("conexiuni.out", "w", stdout);
    while(scanf("%d ", &a[++n]) == 1);
    n += 2;
    return 0;
}
