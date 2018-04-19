#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[1000][50];
int n, m, nr, t[1000], used[1000];
struct node{
    int x, y;
}sol[1000];
struct nod{
    int x, y, c;
}v[1000];
struct cmp{
    bool operator()(const nod &a, const nod &b)const{
        return a.c < b.c;
    }
};
int findRoot(int i){
    if(i != t[i])
        t[i] = findRoot(t[i]);
    return t[i];
}
bool ok(int x, int y){
    int X = findRoot(x), Y = findRoot(y);
    return X != Y;
}
void solve(int x, int y, int c){
    if(ok(x, y)){
        int X = findRoot(x), Y = findRoot(y);
        t[X] = Y;
        sol[++nr].x = x;
        sol[nr].y = y;
    }
}
int distanta(char *s1, char *s2){
    int n1 = strlen(s1); int n2 = strlen(s2);
    int *ci1 = new int[n2 + 1]; int *ci = new int[n2 + 1];
    for(int j = 0;j <= n2; j++)
        ci1[j] = j;
    for(int i = 1; i <= n1; i++){
        ci[0] = i;
        for(int j = 1; j <= n2; j++)
            if(s1[i - 1] == s2[j - 1])
                ci[j] = ci1[j - 1];
            else
                ci[j] = 1 + min(min(ci1[j], ci[j-1]), ci1[j - 1]);
        for(int j = 0; j <= n2; j++)
            ci1[j] = ci[j];
    }
    return ci[n2];
}
int main(){
    freopen("cuvinte.in", "r", stdin);
    int k;
    scanf("%d ", &k);
    while(scanf("%s ", s[++n]) == 1);
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            v[++m].x = i,
            v[m].y = j,
            v[m].c = distanta(s[i], s[j]);
    for(int i = 1; i <= n; ++i)
        t[i] = i;
    sort(v + 1, v + m + 1, cmp());
    int l = 0, grad = 0;
    for(l = 1; l <= m && nr < n - k; ++l)
        solve(v[l].x, v[l].y, v[l].c);
    for(; l <= m; ++l)
        if(ok(v[l].x, v[l].y)){
            grad = v[l].c;
            break;
        }
    for(int j = 1; j <= k; ++j){
        int val = 0;
        for(int i = 1; i <= nr; ++i)
            if(!used[sol[i].x] && !used[sol[i].y]){
                printf("%s %s ", s[sol[i].x], s[sol[i].y]);
                used[sol[i].x] = used[sol[i].y] = true;
                val = t[sol[i].x];
                break;
            }
        for(int i = 1; i <= nr; ++i){
            if(t[sol[i].x] == val && !used[sol[i].x]){
                printf("%s ", s[sol[i].x]);
                used[sol[i].x] = true;
            }
            if(t[sol[i].y] == val && !used[sol[i].y]){
                printf("%s ", s[sol[i].y]);
                used[sol[i].y] = true;
            }
        }
        if(val)
            printf("\n");
    }
    for(int i = 1; i <= n; ++i)
        if(!used[i])
            printf("%s\n", s[i]);
    printf("%d\n", grad);
    return 0;
}
