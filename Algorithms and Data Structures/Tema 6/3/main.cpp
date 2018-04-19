#include <cstdio>
using namespace std;
struct nod{
    int x;
    nod *l, *r;
}*first, *last;
void push_b(int x){
    if(first == NULL){
        first = new nod;
        first->x = x;
        first->l = first->r = NULL;
        last = first;
        return;
    }
    nod *q;
    q = new nod;
    q->x = x;
    q->r = NULL;
    q->l = last;
    last->r = q;
    last = q;
}
void push_f(int x){
    if(first == NULL){
        first = new nod;
        first->x = x;
        first->l = first->r = NULL;
        last = first;
        return;
    }
    nod *q;
    q = new nod;
    q->x = x;
    q->r = first;
    q->l = NULL;
    first->l = q;
    first = q;
}
int pop_b(){
    if(first == NULL){
        printf("Empty DEQUE");
        return -1;
    }
    int x;
    if(first == last){
        x = last->x;
        delete first;
        first = last = NULL;
        return x;
    }
    x = last->x;
    nod *q;
    q = last->l;
    delete last;
    last = q;
    last->r = NULL;
    return x;
}
int pop_f(){
    if(first == NULL){
        printf("Empty DEQUE");
        return -1;
    }
    int x;
    if(first == last){
        x = first->x;
        delete first;
        first = last = NULL;
        return x;
    }
    x = first->x;
    nod *q;
    q = first->r;
    delete first;
    first = q;
    last->l = NULL;
    return x;
}
int main(){
    push_f(1);
    push_b(2);
    printf("%d\n", pop_b());
    printf("%d\n\n", pop_f());
    push_f(3);
    push_b(1);
    printf("%d\n", pop_b());
    printf("%d\n", pop_f());
    return 0;
}
