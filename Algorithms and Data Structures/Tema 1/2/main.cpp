#include <cstdio>
using namespace std;
int n, v[100];
int main(){
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d\n", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d ", &v[i]);
    for(int i = 2; i <= n; ++i){
        int t = v[i], j = i;
        while(t < v[j - 1] && j > 1)
            v[j] = v[j - 1], --j;
        v[j] = t;
    }
    for(int i = 1; i <= n; ++i)
        printf("%d ", v[i]);
    return 0;
}
