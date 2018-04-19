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
    q->l = start;
    if(start->r == NULL){
        start->r = q;
        start->l = q;
        q->r = start;
        return;
    }
    start->r->l = q;
    q->r = start->r;
    start->r = q;
}
int pop(){
    int x;
    if(start->l == start->r){
        x = start->r->key;
        delete start->l;
        start->l = start->r = NULL;
        return x;
    }
    nod *q;
    q = start->l;
    x = q->key;
    q->l->r = start;
    start->l = q->l;
    delete q;
    return x;
}
int main(){
    start = new nod;
    start->l = NULL;
    start->r = NULL;
    push(1);
    push(2);
    pop();
    pop();
    push(1);
    push(2);
    printf("%d\n", pop());
    printf("%d", pop());
    return 0;
}
