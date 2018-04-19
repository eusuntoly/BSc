#include <cstdio>
using namespace std;
struct pol{
    int gr, coef;
    pol *next;
} *p, *q, *s;
int n, m;
void add(pol *r){
    if(s == NULL){
        s = new pol;
        s->coef = r->coef;
        s->gr = r->gr;
        s->next = NULL;
        delete r;
        return;
    }
    if(r->gr > s->gr){
        pol *t;
        t = new pol;
        t->coef = r->coef;
        t->gr = r->gr;
        t->next = s;
        s = t;
        delete r;
        return;
    }
    pol *t, *l;
    l = NULL;
    t = s;
    while(t != NULL && r->gr < t->gr)l = t, t = t->next;
    if(t!= NULL && t->gr == r->gr) t->coef += r->coef, delete r;
    else{
        pol *a;
        a = new pol;
        a->coef = r->coef;
        a->gr = r->gr;
        a->next = t;
        if(l != NULL)
            l->next = a;
        delete r;
    }
}
void produs(pol *r, pol *t){
    while(r != NULL){
        pol *l;
        l = t;
        while(l != NULL){
            pol *b;
            b = new pol;
            b->coef = r->coef * l->coef;
            b->gr = r->gr + l->gr;
            b->next = NULL;
            add(b);
            l = l->next;
        }
        r = r->next;
    }
}
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d %d", &n, &m);
    p = new pol;
    scanf("%d %d ", &p->coef, &p->gr);
    p->next = NULL;
    pol *r, *t;
    r = p;
    for(int i = n - 1; i > 0; --i){
        t = new pol;
        scanf("%d %d", &t->coef, &t->gr);
        t->next = NULL;
        r->next = t;
        r = t;
    }
    q = new pol;
    scanf("%d %d ", &q->coef, &q->gr);
    q->next = NULL;
    r = q;
    for(int i = m - 1; i > 0; --i){
        t = new pol;
        scanf("%d %d", &t->coef, &t->gr);
        t->next = NULL;
        r->next = t;
        r = t;
    }
    produs(p, q);
    r = s;
    printf("%dX^%d", r->coef, r->gr);
    r = r->next;
    while(r != NULL){
        printf("+%dX^%d", r->coef, r->gr);
        r = r->next;
    }
    return 0;
}
