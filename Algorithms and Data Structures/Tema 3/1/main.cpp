#include <cstdio>
using namespace std;
struct nod{
    int val;
    nod *leg;
} *first;
int n, x;
void inser(int a){
    nod *q;
    q = new nod;
    q->val = a;
    q->leg = NULL;
    if(a < first->val){
        q->leg = first;
        first = q;
        return;
    }
    nod *p, *r;
    p = first;
    r = first->leg;
    while(r != NULL && a > r->val){
        p = r;
        r = r->leg;
    }
    q->leg = r;
    p->leg = q;
}
int main(){
    scanf("%d", &n);
    scanf("%d", &x);
    first = new nod;
    first->val = x;
    first->leg = NULL;
    for(int i = 2; i <= n; ++i){
        scanf("%d", &x);
        inser(x);
    }
    nod *p;
    p = first;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->leg;
    }
    printf("\n");
    return 0;
}
