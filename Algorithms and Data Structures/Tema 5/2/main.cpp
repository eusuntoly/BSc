#include <cstdio>
#include <cstring>
using namespace std;
char s[100];
struct nod{
    char x;
    nod *next;
} *Q;
bool empty(nod *Q){
    return Q == NULL ? true : false;
}
void push(char a){
    nod *q;
    q = new nod;
    q->x = a;
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
            push(s[i]);
        else{
            if(s[i] != peek())
                pop();
            else
                push(s[i]);
        }
    }
    if(empty(Q))
        printf("Da.\n");
    else
        printf("Nu.\n");
    return 0;
}
