#include <cstdio>
using namespace std;
struct nod{
    int key;
    nod *l, *r;
} *start;
void push(int x){
    nod *q;
    q = new nod;
    q->key = x;
    q->r = start;
    if(start->r == NULL){
        start->r = q;
        start->l = q;
        q->l = start;
        return;
    }
    start->l->r = q;
    q->l = start->l;
    start->l = q;
}
void pop(int x){
    if(start->l == start->r){
        delete start->l;
        start->l = start->r = NULL;
        return;
    }
    nod *q;
    q = start->r;
    while(q->key != x) q = q->r;
    q->l->r = q->r;
    q->r->l = q->l;
    delete q;
}
int main(){
    start = new nod;
    start->l = NULL;
    start->r = NULL;
    push(1);
    push(2);
    pop(1);
    pop(2);
    push(1);
    push(2);
    printf("%d", start->r->key);
    return 0;
}
