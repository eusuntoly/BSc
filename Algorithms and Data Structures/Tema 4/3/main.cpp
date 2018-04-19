#include <cstdio>
using namespace std;
struct nod{
    int val;
    nod *leg;
}*A, *B, *C;
int n;
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d", &n);
    C = new nod;
    scanf("%d ", &C->val);
    C->leg = NULL;
    nod *p, *q, *r;
    p = C;
    for(int i = 2; i <= n; ++i){
        q = new nod;
        scanf("%d ", &q->val);
        q->leg = NULL;
        p->leg = q;
        p = q;
    }
    A = C;
    B = C->leg;
    p = C->leg->leg;
    q = A;
    r = B;
    for(int i = 3; i <= n; ++i){
        if(i % 2)
            q->leg = p,
            q = q->leg;
        else
            r->leg = p,
            r = r->leg;
        p = p->leg;
    }
    if(q) q->leg = NULL;
    if(r) r->leg = NULL;
    q = A;
    r = B;
    while(q != NULL){
        printf("%d ", q->val);
        q = q->leg;
    }
    printf("\n");
    while(r != NULL){
        printf("%d ", r->val);
        r = r->leg;
    }
    printf("\n");
    return 0;
}
