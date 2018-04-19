#include <cstdio>
#include <algorithm>
#define N 200001
#define M 400001
using namespace std;
int n, m, nr, t[N];
long long s;
struct node{
    int x, y;
}sol[M];
struct nod{
    int x, y, c;
}v[M];
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
        s += c;
    }
}
int main(){
    freopen("grafpond.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; ++i)
        t[i] = i;
    for(int i = 1; i <= m; ++i)
        scanf("%d %d %d\n", &v[i].x, &v[i].y, &v[i].c);
    sort(v + 1, v + m + 1, cmp());
    for(int i = 1; i <= m; ++i)
        solve(v[i].x, v[i].y, v[i].c);
    printf("%lld\n", s);
    printf("%d\n", nr);
    for(int i = 1; i <= nr; ++i)
        printf("%d %d\n", sol[i].x, sol[i].y);
    return 0;
}
