#include <cstdio>
using namespace std;
struct pol{
    int gr, coef;
    pol *next;
} *p, *q, *s;
int n, m;
void add(pol *r, pol *t){
    pol *a, *b;
    s = new pol;
    if(r->gr == t->gr){
        s->gr = r->gr;
        s->coef = r->coef + t->coef;
        r = r->next;
        t = t->next;
    }
    else
        if(r->gr > t->gr){
            s->gr = r->gr;
            s->coef = r->coef;
            r = r->next;
        }
        else{
            s->gr = t->gr;
            s->coef = t->coef;
            t = t->next;
        }
    s->next = NULL;
    a = s;
    while(r != NULL && t != NULL){
        if(r->gr == t->gr){
            b = new pol;
            b->gr = r->gr;
            b->coef = r->coef + t->coef;
            b->next = NULL;
            a->next = b;
            a = b;
            r = r->next;
            t = t->next;
        }
        else
            if(r->gr > t->gr){
                b = new pol;
                b->gr = r->gr;
                b->coef = r->coef;
                b->next = NULL;
                a->next = b;
                a = b;
                r = r->next;
            }
            else{
                b = new pol;
                b->gr = t->gr;
                b->coef = t->coef;
                b->next = NULL;
                a->next = b;
                a = b;
                t = t->next;
            }
    }
    while(r != NULL){
        b = new pol;
        b->gr = r->gr;
        b->coef = r->coef;
        b->next = NULL;
        a->next = b;
        a = b;
        r = r->next;
    }
    while(t != NULL){
        b = new pol;
        b->gr = t->gr;
        b->coef = t->coef;
        b->next = NULL;
        a->next = b;
        a = b;
        t = t->next;
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
    add(p, q);
    r = s;
    printf("%dX^%d", r->coef, r->gr);
    r = r->next;
    while(r != NULL){
        printf("+%dX^%d", r->coef, r->gr);
        r = r->next;
    }
    return 0;
}
