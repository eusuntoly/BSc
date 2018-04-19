#include <cstdio>
using namespace std;
int n, v[100];
int caut(int x){
    int i, cnt;
    for(cnt = 1; cnt < n; cnt <<= 1);
    for(i = 0; cnt; cnt >>= 1)
        if(i + cnt < n && v[i + cnt] <= x)
           i += cnt;
    if(v[i] != x)
        return -1;
    return i;
}
int main(){
    freopen("d.in", "r",stdin);
    freopen("d.out", "w", stdout);
    scanf("%d\n", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d ", &v[i]);
    int rez = caut(4);
    if(rez >= 0)
        printf("Numarul cautat este pe pozitia %d.\n", rez + 1);
    else
        printf("Numarul cautat nu se gaseste in sir.\n");
    return 0;
}
