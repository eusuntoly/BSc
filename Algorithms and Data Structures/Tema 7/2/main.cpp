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
void del(nod *route, int x){
    if(route->x < x){
        pred = route;
        del(route->r, x);
        return;
    }
    if(route->x > x){
        pred = route;
        del(route->l, x);
        return;
    }
    if(route->l == NULL && route->r == NULL){
        if(route == top)
            delete top,
            top = NULL;
        else
            if(pred->l == route)
                pred->l = NULL;
            else
                pred->r = NULL;
        delete route;
        return;
    }
    if(route->l != NULL){
        nod *q;
        q = route->l;
        pred = route;
        while(q->r != NULL)
            pred = q,
            q = q->r;
        route->x = q->x;
        if(pred == route)
            pred->l = q->l;
        else
            pred->r = q->l;
        delete q;
        return;
    }
    else{
        nod *q;
        q = route->r;
        pred = route;
        while(q->l != NULL)
            pred = q,
            q = q->l;
        route->x = q->x;
        if(pred == route)
            pred->r = q->l;
        else
            pred->l = q->l;
        delete q;
    }
}
void srd(nod *p){
    if(p == NULL) return;
    srd(p->l);
    printf("%d ", p->x);
    srd(p->r);
}
void rsd(nod *p){
    if(p == NULL)
        return;
    printf("%d ", p->x);
    rsd(p->l);
    rsd(p->r);
}
int main(){
    top = insert(top, 4);
    insert(top, 1);
    insert(top, 7);
    insert(top, 3);
    insert(top, 5);
    insert(top, 2);
    insert(top, 6);
    srd(top);
    printf("\n");
    rsd(top);
    printf("\n\n");
    del(top, 4);
    srd(top);
    printf("\n");
    rsd(top);
    return 0;
}
