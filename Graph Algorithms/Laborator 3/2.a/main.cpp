#include <cstdio>
using namespace std;
int n, d[100], s[100];
int main(){
    freopen("retea.in", "r", stdin);
    freopen("rezultat.out", "w", stdout);
    scanf("%d\n", &n);
    int x, y;
    while(scanf("%d %d\n", &x, &y) == 2)
        if(!d[x] || !d[y]){
            ++d[x];
            ++d[y];
            s[x] += y;
            s[y] += x;
         }
    int i = 1, j = 0, nr = 0;
    while(nr < n - 2){
        ++nr;
        if(!j || j >= i){
            while(d[i] != 1)
                i++;
            printf("%d ", s[i]);
            s[s[i]] -= i;
            --d[s[i]];
            j = s[i];
            d[i] = 0;
        }
        else
            if(d[j]==1){
                printf("%d ", s[j]);
                s[s[j]] -= j;
                --d[s[j]];
                d[j] = 0;
                j = s[j];
            }
    }
    return 0;
}
