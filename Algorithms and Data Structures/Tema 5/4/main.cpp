#include <cstdio>
#include <cstring>
using namespace std;
int v[100], n;
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
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    for(int i = 1; i <= n; ++i){
        if(empty(Q))
            push(i);
        else{
            if(v[i] == peek())
                pop();
            else
                push(i);
        }
    }
    if(empty(Q))
        printf("Da.\n");
    else
        printf("Nu.\n");
    return 0;
}
