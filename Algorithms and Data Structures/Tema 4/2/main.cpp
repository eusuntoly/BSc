#include <cstdio>
using namespace std;
struct nod{
    int val;
    nod *next;
}*A, *B, *C;
int n, m;
void solve(){
    if(A->val < B->val) C = A, A = A->next;
    else C = B, B = B->next;
    nod *p;
    p = C;
    while(A != NULL && B != NULL){
        if(A->val < B->val)
            p->next = A, p = A, A = A->next;
        else
            p->next = B, p = B, B = B->next;
    }
    while(A !=  NULL)
        p->next = A, p = A, A = A->next;
    while(B != NULL)
        p->next = B, p = B, B = B->next;
}
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d %d", &n, &m);
    A = new nod;
    scanf("%d", &A->val);
    A->next = NULL;
    nod *p, *q;
    p = A;
    for(int i = 2; i <= n; ++i){
        q = new nod;
        scanf("%d", &q->val);
        q->next = NULL;
        p->next = q;
        p = q;
    }
    B = new nod;
    scanf("%d", &B->val);
    B->next = NULL;
    p = B;
    for(int i = 2; i <= m; ++i){
        q = new nod;
        scanf("%d", &q->val);
        q->next = NULL;
        p->next = q;
        p = q;
    }
    solve();
    p = C;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return 0;
}
