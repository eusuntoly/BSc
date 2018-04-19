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
    while(p != NULL){
        if(p->val % 2 ){
            ++nr_impar;
            s += p->val;
        }
        else
            ++nr_par;
        p = p->leg;
    }
    printf("%d %f\n", nr_par, s/nr_impar);
    return 0;
}
