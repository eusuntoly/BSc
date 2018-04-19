#include <cstdio>
using namespace std;
struct nod{
    int val;
    nod *leg;
} *first;
int n, x, nr_par, nr_impar;
float s;
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &x);
    first = new nod;
    first->val = x;
    first->leg = NULL;
    nod *p;
    p = first;
    for(int i = 2; i <= n; ++i){
        scanf("%d", &x);
        nod *q;
        q = new nod;
        q->val = x;
        q->leg = NULL;
        p->leg = q;
        p = q;
    }
    p = first;
    while(p->leg != NULL){
        nod *q;
        q = new nod;
        q->val = (p->leg->val + p->val) / 2;
        q->leg = p->leg;
        p->leg = q;
        p = q->leg;
    }
    p = first;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->leg;
    }
    printf("\n");
    return 0;
}
