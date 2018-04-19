#include <cstdio>
#include <cstring>
using namespace std;
char s[2][50];
int n, m, ok = 1;
struct nod{
    int val;
    nod *leg;
}*a, *b, *S;
void write(nod *p){
    if(p == NULL) return;
    write(p->leg);
    if(!ok) printf("%d", p->val);
    ok = 0;
}
void mul(nod *A, nod *B){
    int t, i, j;
    nod *q, *p;
    S = new nod;
    S->val = 0;
    S->leg = NULL;
    p = S;
    for(i = 1; i <= n; i++){
        q = p;
        nod *C;
        C = B;
        for(t = 0, j = 1; j <= m; ++j, t /= 10){
            q->val = (t += q->val + A->val * C->val) % 10;
            if(q->leg == NULL){
                nod *r;
                r = new nod;
                r->val = 0;
                r->leg = NULL;
                q->leg = r;
            }
            q = q->leg;
            C = C->leg;
        }
        if(t){
            q->val = t;
            t /= 10;
            if(q->leg == NULL){
                nod *r;
                r = new nod;
                r->val = 0;
                r->leg = NULL;
                q->leg = r;
            }
            q = q->leg;
        }
        if(p->leg == NULL){
            nod *r;
            r = new nod;
            r->val = 0;
            r->leg = NULL;
            p->leg = r;
        }
        p = p->leg;
        A = A->leg;
    }
}
int main(){
    scanf("%s %s", s[0], s[1]);
    n = strlen(s[0]);
    m = strlen(s[1]);
    nod *q;
    a = new nod;
    a->val = s[0][n - 1] - 48;
    a->leg = NULL;
    q = a;
    for(int i = n - 2; i >= 0; --i){
        nod *r;
        r = new nod;
        r->val = s[0][i] - 48;
        r->leg = NULL;
        q->leg = r;
        q = r;
    }
    b = new nod;
    b->val = s[1][m - 1] - 48;
    b->leg = NULL;
    q = b;
    for(int i = m - 2; i >= 0; --i){
        nod *r;
        r = new nod;
        r->val = s[1][i] - 48;
        r->leg = NULL;
        q->leg = r;
        q = r;
    }
    mul(a, b);
    write(S);
    printf("\n");
    return 0;
}
