#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define N 201
#define M 10001
using namespace std;
int n, m, nr, t[N];
long long s;
struct nod{
    int x, y, c;
}v[M], sol[M];
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
        sol[nr].c = c;
        s += c;
    }
}
int xx, yy, cc;
bool used[N];
vector< pair<int, int> > liste[N];
void DFS(int a, int b, int x, int y, int c){
    if(a == b){
        xx = x;
        yy = y;
        cc = c;
    }
    for(int i = 0; i < liste[a].size(); ++i)
        if(!used[liste[a][i].first]){
            used[liste[a][i].first] = true;
            if(liste[a][i].second > c)
                DFS(liste[a][i].first, b, a, liste[a][i].first, liste[a][i].second);
            else
                DFS(liste[a][i].first, b, x, y, c);
        }
}
int main(){
    freopen("online.in", "r", stdin);
    freopen("online.out", "w", stdout);
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; ++i)
        t[i] = i;
    for(int i = 1; i <= m; ++i)
        scanf("%d %d %d\n", &v[i].x, &v[i].y, &v[i].c);
    sort(v + 1, v + m + 1, cmp());
    for(int i = 1; i <= m; ++i)
        solve(v[i].x, v[i].y, v[i].c);
    printf("%lld\n", s);
    int k;
    scanf("%d ", &k);
    for(int i = 1; i <= k; ++i){
        int x, y, c, ok = 0;
        scanf("%d %d %d ", &x, &y, &c);
        for(int j = 1; j <= nr; ++j)
            if((sol[j].x == x && sol[j].y == y) || (sol[j].x == y && sol[j].y == x)){
                ok = 1;
                if(sol[j].c > c)
                    s -= (sol[j].c - c),
                    sol[j].c = c;
            }
        if(!ok){
            for(int j = 1; j <= n; ++j)
                liste[j].clear();
            xx = yy = cc = 0;
            memset(used, 0, sizeof(used));
            for(int j = 1; j <= nr; ++j)
                liste[sol[j].x].push_back( make_pair(sol[j].y, sol[j].c) ),
                liste[sol[j].y].push_back( make_pair(sol[j].x, sol[j].c) );
                used[x] = true;
                DFS(x, y, 0, 0, 0);
            if(cc > c)
                for(int j = 1; j <= nr; ++j)
                    if((sol[j].x == xx && sol[j].y == yy) || (sol[j].x == yy && sol[j].y == xx))
                        sol[j].x = x,
                        sol[j].y = y,
                        s -= (cc - c),
                        sol[j].c = c;
        }
        printf("%lld\n", s);
    }
    return 0;
}
