#include <cstdio>
using namespace std;
int n, v[100];
int main(){
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d\n", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d ", &v[i]);
    int m = n;
    for(int i = 1; i <= n; ++i){
        int poz = 1;
        for(int i = 2; i <= m; ++i)
            if(v[i] < v[poz]) poz = i;
        int aux = v[m];
        v[m] = v[poz];
        v[poz] = aux;
        --m;
    }
    for(int i = 1; i <= n; ++i)
        printf("%d ", v[i]);
    return 0;
}
