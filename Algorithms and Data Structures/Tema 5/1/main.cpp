#include <cstdio>
using namespace std;
struct nod{
    int x;
    nod *next;
} *Q;
bool empty(nod *Q){
    return Q == NULL ? true : false;
}
void push(int a){
    nod *q;
    q = new nod;
    q->x = a;
    q->next = Q;
    Q = q;
}
int pop(){
    int x = -1;
    nod *q;
    q = Q;
    if(!empty(Q))
        x = Q->x,
        Q = Q->next;
    delete q;
    return x;
}
int peek(){
    if(!empty(Q))
         return Q->x;
    return -1;
}
int search(int x){
    int nr = 0;
    nod *q;
    q = Q;
    while(!empty(q) && q->x != x)
        ++nr,
        q = q->next;
    if(!empty(q))
        return nr;
    return -1;
}
void afis(){
    nod *q;
    q = Q;
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
