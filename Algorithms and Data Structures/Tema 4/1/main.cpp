#include <cstdio>
using namespace std;
struct nod{
    int val;
    nod *leg;
} *prim, *ultim, *B, *r;
int n;
void read(){
    freopen("d.in", "r",stdin);
    scanf("%d", &n);
    prim = new nod;
    scanf("%d", &prim->val);
    prim->leg = NULL;
    nod *q, *p;
    q = prim;
    for(int i = 2; i < n; ++i){
        p = new nod;
        scanf("%d ", &p->val);
        p->leg = NULL;
        q->leg = p;
        q = p;
    }
    ultim = new nod;
    scanf("%d", &ultim->val);
    ultim->leg = NULL;
    q->leg = ultim;
}
void solve1(nod *p){
    if(p->leg != NULL)
        solve1(p->leg);
    if(p->leg == NULL){
        B = new nod;
        B->val = p->val;
        B->leg = NULL;
        r = B;
        return;
    }
    nod *q;
    q = new nod;
    q->val = p->val;
    q->leg = NULL;
    r->leg = q;
    r = q;
    return;
}
void solve2(nod *p, nod *q){
    if(q->leg != NULL)
        solve2(q, q->leg);
    q->leg = p;
    if(p == NULL){
        prim  = ultim;
    }
    return;
}
void write(nod *p){
    while(p != NULL){
        printf("%d ", p->val);
        p = p->leg;
    }
    printf("\n");
}
int main(){
    read();
    solve1(prim);
    solve2(NULL, prim);
    write(B);
    write(prim);
    return 0;
}
