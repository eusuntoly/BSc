#include <cstdio>
using namespace std;
struct vect{
    int val, cnt;
    vect *next;
}*p, *q, *s;
int n;
void sum(vect *r, vect *t){
    vect *a, *b;
    s = new vect;
    if(r->cnt == t->cnt){
        s->cnt = r->cnt;
        s->val = r->val + t->val;
        r = r->next;
        t = t->next;
    }
    else
        if(r->cnt < t->cnt){
            s->cnt = r->cnt;
            s->val = r->val;
            r = r->next;
        }
        else{
            s->cnt = t->cnt;
            s->val = t->val;
            t = t->next;
        }
    s->next = NULL;
    a = s;
    while(r != NULL && t != NULL){
        if(r->cnt == t->cnt){
            b = new vect;
            b->cnt = r->cnt;
            b->val = r->val + t->val;
            b->next = NULL;
            a->next = b;
            a = b;
            r = r->next;
            t = t->next;
        }
        else
            if(r->cnt < t->cnt){
                b = new vect;
                b->cnt = r->cnt;
                b->val = r->val;
                b->next = NULL;
                a->next = b;
                a = b;
                r = r->next;
            }
            else{
                b = new vect;
                b->cnt = t->cnt;
                b->val = t->val;
                b->next = NULL;
                a->next = b;
                a = b;
                t = t->next;
            }
    }
    while(r != NULL){
        b = new vect;
        b->cnt = r->cnt;
        b->val = r->val;
        b->next = NULL;
        a->next = b;
        a = b;
        r = r->next;
    }
    while(t != NULL){
        b = new vect;
        b->cnt = t->cnt;
        b->val = t->val;
        b->next = NULL;
        a->next = b;
        a = b;
        t = t->next;
    }
}
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d ", &n);
    vect *r, *t;
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d ", &x);
        if(x){
            if(p == NULL){
                p = new vect;
                p->val = x;
                p->cnt = i;
                p->next = NULL;
                t = p;
            }
            else{
                r = new vect;
                r->val = x,
                r->cnt = i,
                r->next = NULL;
                t->next = r;
                t = r;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d ", &x);
        if(x){
            if(q == NULL){
                q = new vect;
                q->val = x;
                q->cnt = i;
                q->next = NULL;
                t = q;
            }
            else{
                r = new vect;
                r->val = x,
                r->cnt = i,
                r->next = NULL;
                t->next = r;
                t = r;
            }
        }
    }
    sum(p, q);
    int i = 1;
    r = s;
    while(i <= n && r != NULL){
        while(i < r->cnt)
            ++i,
            printf("0 ");
        printf("%d ", r->val);
        ++i;
        r = r->next;
    }
    while(i <= n){
        printf("0 ");
        ++i;
    }
    int prod = 0;
    r = p;
    t = q;
    while(r != NULL && t != NULL){
        if(r->cnt == t->cnt){
            prod += r->val * t->val;
            r = r->next;
            t = t->next;
        }
        else
            if(r->cnt < t->cnt)
                r = r->next;
            else
                t = t->next;
    }
    printf("\n%d\n", prod);
    return 0;
}
