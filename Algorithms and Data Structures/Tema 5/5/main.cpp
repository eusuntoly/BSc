#include <cstdio>
using namespace std;
struct nod{
    int x;
    nod *next;
} *first, *last;
bool empty(nod *Q){
    return Q == NULL ? true : false;
}
void push(int a){
    if(empty(first)){
        first = new nod;
        first->x = a;
        first->next = NULL;
        last = first;
        return;
    }
    nod *q;
    q = new nod;
    q->x = a;
    q->next = NULL;
    last->next = q;
    last = q;
}
int pop(){
    int x = -1;
    nod *q;
    q = first;
    if(!empty(q)){
        x = q->x;
        if(first == last)
            first = NULL,
            last = NULL;
        else
            first = first->next;
    }
    delete q;
    return x;
}
int peek(){
    if(!empty(first))
         return first->x;
    return -1;
}
int search(int x){
    int nr = 0;
    nod *q;
    q = first;
    while(!empty(q) && q->x != x)
        ++nr,
        q = q->next;
    if(!empty(q))
        return nr;
    return -1;
}
void afis(){
    nod *q;
    q = first;
    if(empty(q))
        printf("Stiva este vida.");
    while(!empty(q)){
        printf("%d ", q->x);
        q = q->next;
    }
    printf("\n");
}
int main(){
    push(1);
    push(2);
    push(3);
    afis();
    pop();
    afis();
    pop();
    afis();
    pop();
    afis();
    pop();
    afis();
    return 0;
}
