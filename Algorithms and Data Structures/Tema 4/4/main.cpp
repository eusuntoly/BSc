#include <cstdio>
using namespace std;
int n, m, N, M;
struct column{
    int j, value;
    column *next;
} *C;
struct line{
    int i;
    line *next;
    column *el;
}*a, *b, *L, *s;
void add(line *&v, int i, int j, int val){
    if(v == NULL){
        v = new line;
        C = new column;
        v->i = i;
        v->next = NULL;
        v->el = C;
        L = v;
        C->j = j;
        C->value = val;
        C->next = NULL;
        return;
    }
    if(i != L->i){
        line *l;
        C = new column;
        C->j = j;
        C->value = val;
        C->next = NULL;
        l = new line;
        l->i = i;
        l->next = NULL;
        l->el = C;
        L->next = l;
        L = l;
        return;
    }
    column *c;
    c = new column;
    c->j = j;
    c->value = val;
    c->next = NULL;
    C->next = c;
    C = c;
}
int main(){
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j){
            int x;
            scanf("%d", &x);
            add(a, i, j, x);
        }
    scanf("%d %d", &n, &m);
    N = n < N ? N : n;
    M = m < M ? M : m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            int x;
            scanf("%d", &x);
            add(b, i, j, x);
        }
    line *l1, *l2, *ls;
    column *c1, *c2, *cs;
    l1 = a;
    l2 = b;
    s = new line;
    if(l1->i < l2->i){
            s = l1;
            l1 = l1->next;
            s->next = NULL;
        }
   else
        if(l1->i < l2->i){
            s = l2;
            l2 = l2->next;
            s->next = NULL;
        }
    else{
        c1 = l1->el;
        c2 = l2->el;
        cs = new column;
        s->el = cs;
        s->i = l1->i;
        s->next = NULL;
        if(c1->j < c2->j) cs->j = c1->j, cs->value = c1->value, c1 = c1->next, cs->next = NULL;
        else if(c1->j > c2->j) cs->j = c2->j, cs->value = c2->value, c2 = c2->next, cs->next = NULL;
        else cs->j = c1->j, cs->value = c1->value + c2->value, c1 = c1->next, c2 = c2->next, cs->next = NULL;
        while(c1 && c2){
            column *c;
            c = new column;
            cs->next = c;
            cs = c;
            if(c1->j < c2->j) cs->j = c1->j, cs->value = c1->value, c1 = c1->next, cs->next = NULL;
            else if(c1->j > c2->j) cs->j = c2->j, cs->value = c2->value, c2 = c2->next, cs->next = NULL;
            else cs->j = c1->j, cs->value = c1->value + c2->value, c1 = c1->next, c2 = c2->next, cs->next = NULL;
        }
        while(c1){
            column *c;
            c = new column;
            cs->next = c;
            cs = c;
            cs->j = c1->j, cs->value = c1->value, c1 = c1->next, cs->next = NULL;
        }
        while(c2){
            column *c;
            c = new column;
            cs->next = c;
            cs = c;
            cs->j = c2->j, cs->value = c2->value, c2 = c2->next, cs->next = NULL;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    ls = s;
    while(l1 && l2){
        if(l1->i < l2->i){
            ls->next = l1;
            ls = l1;
            l1 = l1->next;
            ls->next = NULL;
        }
        else
            if(l1->i < l2->i){
                ls->next = l2;
                ls = l2;
                l2 = l2->next;
                ls->next = NULL;
            }
        else{
            line *l;
            l = new line;
            ls->next = l;
            ls = l;
            c1 = l1->el;
            c2 = l2->el;
            cs = new column;
            ls->el = cs;
            ls->i = l1->i;
            ls->next = NULL;
            if(c1->j < c2->j) cs->j = c1->j, cs->value = c1->value, c1 = c1->next, cs->next = NULL;
            else if(c1->j > c2->j) cs->j = c2->j, cs->value = c2->value, c2 = c2->next, cs->next = NULL;
            else cs->j = c1->j, cs->value = c1->value + c2->value, c1 = c1->next, c2 = c2->next, cs->next = NULL;
            while(c1 && c2){
                column *c;
                c = new column;
                cs->next = c;
                cs = c;
                if(c1->j < c2->j) cs->j = c1->j, cs->value = c1->value, c1 = c1->next, cs->next = NULL;
                else if(c1->j > c2->j) cs->j = c2->j, cs->value = c2->value, c2 = c2->next, cs->next = NULL;
                else cs->j = c1->j, cs->value = c1->value + c2->value, c1 = c1->next, c2 = c2->next, cs->next = NULL;
            }
            while(c1){
                column *c;
                c = new column;
                cs->next = c;
                cs = c;
                cs->j = c1->j, cs->value = c1->value, c1 = c1->next, cs->next = NULL;
            }
            while(c2){
                column *c;
                c = new column;
                cs->next = c;
                cs = c;
                cs->j = c2->j, cs->value = c2->value, c2 = c2->next, cs->next = NULL;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    while(l1){
        ls->next = l1;
        ls = l1;
        l1 = l1->next;
        ls->next = NULL;
    }
    while(l2){
        ls->next = l2;
        ls = l2;
        l2 = l2->next;
        ls->next = NULL;
    }
    line *l;
    column *c;
    l = s;
    for(int i = 1; i <= N; ++i){
        if(l->i == i){
            c = l->el;
            for(int j = 1; j <= M; ++j)
                if(c->j == j)
                    printf("%d ", c->value),
                    c = c->next;
                else
                    printf("0 ");
            l = l->next;
        }
        else
            for(int j = 1; j <= M; ++j)
                printf("0 ");
        printf("\n");
    }
    return 0;
}
