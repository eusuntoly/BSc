#include <cstdio>
using namespace std;
int v[100], ok, n;
int main(){
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d\n", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d ", &v[i]);
    int m = n;
    while(!ok){
        ok = 1;
        for(int i = 1; i < m; ++i)
            if(v[i] > v[i + 1]){
                ok = 0;
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        --m;
    }
    for(int i = 1; i <= n; ++i)
        printf("%d ", v[i]);
    return 0;
}
