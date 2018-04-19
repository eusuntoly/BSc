#include <cstdio>
using namespace std;
int n;
struct nod{
    int x;
    nod *next;
};
struct coada{
    nod *first, *last;
} Q[100];
void push(int x, int p){
    ++n;
    if(Q[p].first == NULL){
        Q[p].first = new nod;
        Q[p].first->x = x;
        Q[p].first->next = NULL;
        Q[p].last = Q[p].first;
        return;
    }
    nod *q;
    q = new nod;
    q->x = x;
    q->next = NULL;
    Q[p].last->next = q;
    Q[p].last = q;
}
int pop(){
    if(!n){
        printf("Stiva este vida.\n");
        return -1;
    }
    --n;
    int x, p;
    for(int i = 1; i <= 100; ++i)
        if(Q[i].first != NULL){ p = i; break;}
    x = Q[p].first->x;
    if(Q[p].first == Q[p].last){
        delete Q[p].first;
        Q[p].first = NULL;
        Q[p].last = NULL;
        return x;
    }
    nod *q;
    q = Q[p].first;
    Q[p].first = Q[p].first->next;
    delete q;
    return x;
}
int main(){
    push(1, 1);
    push(2, 3);
    push(3, 1);
    push(11, 1);
    push(22, 3);
    push(33, 1);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    pop();
    return 0;
}
