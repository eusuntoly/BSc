#include <cstdio>
#include <cstring>
#define N 36002
#define inf 0x3f3f3f3f
#define L ((i)<<1)
#define R ((L)+1)
#define T ((i)>>1)
struct nod{
    int x, cost;
    nod *n;
};
nod *a[N];
int n, m, H[N], poz[N], nh, k, s, list[N], parent[N];
long long d[N];
void swap(int i, int j){
    int t = H[i];
    H[i] = H[j];
    H[j] = t;
    poz[H[i]] = i;
    poz[H[j]] = j;
}
void upheap(int i){
    if(i <= 1)
        return;
    if(d[H[T]] > d[H[i]])
        swap(i, T),
        upheap(T);
}
void downheap(int i){
    int m = i;
    if(L <= nh)
        if(d[H[m]] > d[H[L]])
            m = L;
    if(R <= nh)
        if(d[H[m]] > d[H[R]])
            m = R;
    if(m != i)
        swap(m, i),
        downheap(m);
}
void dijkstra(){
    memset(d, inf, sizeof(d));
    d[n] = 0;
    int i;
    for(i = 1; i <= n; ++i)
        H[i] = poz[i] = i;
    for(i = n / 2; i; --i)
        downheap(i); //creare heap O(n)
    nh = n;
    int u;
    nod *it;
    while(nh){
        u = H[1];
        swap(1, nh--);
        downheap(1);
        for(it = a[u]; it; it = it->n)
            if(d[u] + it->cost < d[it->x] || (d[u] + it->cost == d[it->x] && parent[it->x] > parent[u])){
                d[it->x] = d[u] + it->cost;
                if(parent[u])
                    parent[it->x] = parent[u];
                upheap(poz[it->x]);
            }
    }
    for(int i = 1; i < n; ++i)
        printf("%d ", parent[i] == i ? 0 : parent[i]);
    printf("\n");
}
int main(){
    freopen("catun.in", "r", stdin);
    freopen("catun.out", "w", stdout);
    scanf("%d %d %d\n", &n, &m, &k);
    for(int i = 1; i <= k; ++i){
        scanf("%d", &list[i]);
        parent[list[i]] = list[i];
        nod *t = new nod;
        t->x = n + 1;
        t->cost = 0;
        t->n = a[list[i]];
        a[list[i]] = t;
        nod *l = new nod;
        l->x = list[i];
        l->cost = 0;
        l->n = a[n + 1];
        a[n + 1] = l;
    }
    for(int i = 1; i <= m; ++i){
        int p, q, c;
        scanf("%d %d %d\n", &p, &q, &c);
        nod *t = new nod;
        t->x = q;
        t->cost = c;
        t->n = a[p];
        a[p] = t;
        nod *l = new nod;
        l->x = p;
        l->cost = c;
        l->n = a[q];
        a[q] = l;
    }
    ++n;
    dijkstra();
    return 0;
}
