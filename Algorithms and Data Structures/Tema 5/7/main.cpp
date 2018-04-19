#include <cstdio>
using namespace std;
struct nod{
    int x;
    nod *next;
} *first[100], *last[100];
int n, k;
bool empty(nod *Q){
    return Q == NULL ? true : false;
}
void push(int a, int t){
    if(empty(first[t])){
        first[t] = new nod;
        first[t]->x = a;
        first[t]->next = NULL;
        last[t] = first[t];
        return;
    }
    nod *q;
    q = new nod;
    q->x = a;
    q->next = NULL;
    last[t]->next = q;
    last[t] = q;
}
int pop(int t){
    int x = -1;
    nod *q;
    q = first[t];
    if(!empty(q)){
        x = q->x;
        if(first[t] == last[t])
            first[t] = NULL,
            last[t] = NULL;
        else
            first[t] = first[t]->next;
    }
    delete q;
    return x;
}
int peek(int t){
    if(!empty(first[t]))
         return last[t]->x;
    return -1;
}
void afis(int t){
    nod *q;
    q = first[t];
    if(empty(q))
        printf("Stiva este vida.");
    while(!empty(q)){
        printf("%d ", q->x);
        q = q->next;
    }
    printf("\n");
}
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d %d", &n, &k);
    int ok;
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d", &x);
        ok = 0;
        for(int j = 1; j <= k; ++j)
            if(x > peek(j)){
                push(x, j);
                ok = 1;
                break;
            }
        if(!ok) break;
    }
    if(!ok)
        printf("Nu exista.\n");
    else
        for(int i = 1; i <= k; ++i)
            if(!empty(first[i]))
                afis(i);
    return 0;
}
