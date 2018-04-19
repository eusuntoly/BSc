#include <cstdio>
#include <cstring>
using namespace std;
struct nod{
    int val;
    nod *leg;
} *a, *b, *s;
char x[51], y[51];
void write(nod *l){
    if(l->leg != NULL)
        write(l->leg);
    printf("%d", l->val);
}
int main(){
    scanf("%s%s", x, y);
    a = new nod;
    a->val = x[strlen(x) - 1] - 48;
    a->leg = NULL;
    nod *p, *q;
    q = a;
    for(int i = strlen(x) - 2; i >= 0; --i){
        p = new nod;
        p->val = x[i] - 48;
        p->leg = NULL;
        q->leg = p;
        q = p;
    }
    b = new nod;
    b->val = y[strlen(y) - 1] - 48;
    b->leg = NULL;
    q = b;
    for(int i = strlen(y) - 2; i >= 0; --i){
        p = new nod;
        p->val = y[i] - 48;
        p->leg = NULL;
        q->leg = p;
        q = p;
    }
    int t;
    s = new nod;
    s->val = (a->val + b->val) % 10;
    t = (a->val + b->val) / 10;
    s->leg = NULL;
    nod *r, *c;
    p = a->leg;
    q = b->leg;
    r = s;
    while(q != NULL && p != NULL){
        c = new nod;
        c->val = (p->val + q->val + t) % 10;
        t = (p->val + q->val + t) / 10;
        c->leg = NULL;
        r->leg = c;
        r = c;
        p = p->leg;
        q = q->leg;
    }
    while(p != NULL){
        c = new nod;
        c->val = (p->val + t) % 10;
        t = (p->val + t) / 10;
        c->leg = NULL;
        r->leg = c;
        r = c;
        p = p->leg;
    }
    while(q != NULL){
        c = new nod;
        c->val = (q->val + t) % 10;
        t = (q->val + t) / 10;
        c->leg = NULL;
        r->leg = c;
        r = c;
        q = q->leg;
    }
    if(t){
        c = new nod;
        c->val = t;
        t = 0;
        c->leg = NULL;
        r->leg = c;
    }
    write(s);
    printf("\n");
    return 0;
}
