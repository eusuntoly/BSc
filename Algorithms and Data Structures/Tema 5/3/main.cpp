#include <cstdio>
#include <cstring>
using namespace std;
char s[100];
struct nod{
    char x;
    int i;
    nod *next;
} *Q;
bool empty(nod *Q){
    return Q == NULL ? true : false;
}
void push(char a, int i){
    nod *q;
    q = new nod;
    q->x = a;
    q->i = i;
    q->next = Q;
    Q = q;
}
char pop(){
    int x = -1;
    nod *q;
    q = Q;
    if(!empty(Q))
        x = Q->x,
        Q = Q->next;
    delete q;
    return x;
}
char peek(){
    if(!empty(Q))
         return Q->x;
    return -1;
}
int main(){
    scanf("%s", s);
    for(int i = 0; i < strlen(s); ++i){
        if(empty(Q))
            push(s[i], i);
        else{
            if(s[i] == ')' && s[i] != peek())
                pop();
            else
                push(s[i], i);
        }
    }
    if(empty(Q))
        printf("Da.\n");
    else{
        while(Q->next != NULL && Q->next->x != '(')
            Q = Q->next;
        printf("%d\n", Q->i + 1);
    }
    return 0;
}
