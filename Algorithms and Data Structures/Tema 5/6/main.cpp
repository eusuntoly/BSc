#include <cstdio>
using namespace std;
struct nod{
    int i, j;
    nod *next;
} *first, *last;
int v[100][100], used[100][100], xx[] = {-1, 0, 1, 0}, yy[] = {0, 1, 0, -1}, n, m, nr = 2;
bool empty(nod *Q){
    return Q == NULL ? true : false;
}
void push(int i, int j){
    if(empty(first)){
        first = new nod;
        first->i = i;
        first->j = j;
        first->next = NULL;
        last = first;
        return;
    }
    nod *q;
    q = new nod;
    q->i = i;
    q->j = j;
    q->next = NULL;
    last->next = q;
    last = q;
}
void pop(){
    nod *q;
    q = first;
    if(!empty(q)){
        if(first == last)
            first = NULL,
            last = NULL;
        else
            first = first->next;
    }
    delete q;
}
int main(){
    freopen("d.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &v[i][j]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(v[i][j] && !used[i][j]){
                push(i, j);
                used[i][j] = nr;
                while(!empty(first)){
                    int x = first->i, y = first->j;
                    pop();
                    for(int k = 0; k < 4; ++k)
                        if(v[x + xx[k]][y + yy[k]] && !used[x + xx[k]][y + yy[k]])
                            push(x + xx[k], y + yy[k]),
                            used[x + xx[k]][y + yy[k]] = nr;
                }
                ++nr;
            }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)
            printf("%d ", used[i][j]);
        printf("\n");
    }
    return 0;
}
