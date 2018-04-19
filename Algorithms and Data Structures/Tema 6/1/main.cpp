#include <cstdio>
using namespace std;
struct nod{
    int x;
    nod *l, *r;
} *first, *last;
int n;
bool empty(nod *Q){
    return Q == NULL ? true : false;
}
void push_b(int a){
    ++n;
    if(empty(first)){
        first = new nod;
        first->x = a;
        first->r = NULL;
        first->l = NULL;
        last = first;
        return;
    }
    nod *q;
    q = new nod;
    q->x = a;
    q->r = NULL;
    q->l = NULL;
    last->r = q;
    last = q;
}
void push_f(int a){
    ++n;
    if(empty(first)){
        first = new nod;
        first->x = a;
        first->r = NULL;
        first->l = NULL;
        last = first;
        return;
    }
    nod *q;
    q = new nod;
    q->x = a;
    q->r = NULL;
    q->l = NULL;
    first->l = q;
    first = q;
}
void push_in(int a, int p){
    ++n;
    nod *q, *t;
    q = first;
    t = new nod;
    t->x = a;
    while(p-- > 2)
        q = q->r;
    q->r->l = t;
    t->r = q->r;
    t->l = q;
    q->r = t;

}
void afis_io(){
    nod *q;
    q = first;
    if(empty(q))
        printf("Stiva este vida.");
    while(!empty(q)){
        printf("%d ", q->x);
        q = q->r;
    }
    printf("\n");
}
void afis_po(){
    nod *q;
    q = last;
    if(empty(q))
        printf("Stiva este vida.");
    while(!empty(q)){
        printf("%d ", q->x);
        q = q->l;
    }
    printf("\n");
}
void delete_poz(int p){
    nod *q;
    if(p == 1){
        q = first;
        first = first->r;
        delete q;
        return;
    }
    if(p == n){
        q = last;
        last = last->l;
        delete q;
        return;
    }
    q = first;
    while(p > 2)
        q = q->r;
    q->l->r = q->r;
    q->r->l = q->l;
    delete q;
}
void delete_val(int val){
    nod *q;
    if(val == first->x){
        q = first;
        first = first->r;
        delete q;
        return;
    }
    if(val == last->x){
        q = last;
        last = last->l;
        delete q;
        return;
    }
    q = first;
    while(val != q->x)
        q = q->r;
    q->l->r = q->r;
    q->r->l = q->l;
    delete q;
}
int main(){
    push_f(1);
    push_b(2);
    delete_poz(1);
    delete_poz(1);
    push_f(1);
    push_b(3);
    afis_io();
    return 0;
}
