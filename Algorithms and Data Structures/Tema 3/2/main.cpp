#include <cstdio>
#include <iostream>
using namespace std;
struct pol{
    int gr, coef;
    pol *next;
} *p, *q;
int n, m, a;
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &a);
    pol *r;
    p = new pol;
    scanf("%d", &p->coef);
    p->gr = n;
    p->next = NULL;
    r = p;
    for(int i = 1; i <= n; ++i){
        pol *d;
        d = new pol;
        scanf("%d", &d->coef);
        d->gr = n - i;
        d->next =NULL;
        r->next = d;
        r = d;
    }
    q = new pol;
    scanf("%d", &q->coef);
    q->gr = m;
    q->next = NULL;
    r = q;
    for(int i = 1; i <= m; ++i){
        pol *d;
        d = new pol;
        scanf("%d", &d->coef);
        d->gr = m - i;
        d->next =NULL;
        r->next = d;
        r = d;
    }
    r = p;
    while(r != NULL){
        printf("%d ", r->coef * a);
        r = r->next;
    }
    printf("\n");
    r = q;
    while(r != NULL){
        printf("%d ", r->coef * a);
        r = r->next;
    }
    printf("\n");
    return 0;
}
