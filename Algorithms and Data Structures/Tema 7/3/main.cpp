#include <cstdio>
using namespace std;
struct nod{
    int x;
    nod *l, *r;
} *top, *pred;
nod* insert(nod *route, int x){
    if(route == NULL){
        route = new nod;
        route->x = x;
        route->l = route->r = NULL;
        return route;
    }
    if(x >= route->x){
        if(route->r == NULL)
            route->r = insert(route->r, x);
        else
            insert(route->r, x);
    }

    else{
        if(route->l == NULL)
            route->l = insert(route->l, x);
        else
            insert(route->l, x);
    }
}
bool search(nod *route, int x){
    if(route == NULL)
        return false;
    if(x == route->x)
        return true;
    if(x > route->x)
        return search(route->r, x);
    return search(route->l, x);
}
int findMax(nod *route){
    if(route->r == NULL)
        return route->x;
    return findMax(route->r);
}
void srd(nod *p){
    if(p == NULL) return;
    srd(p->l);
    printf("%d ", p->x);
    srd(p->r);
}
int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    top = insert(top, x);
    for(int i = 1; i < n; ++i)
        scanf("%d", &x),
        insert(top, x);
    srd(top);
    return 0;
}
