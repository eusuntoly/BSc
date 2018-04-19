#include <cstdio>
using namespace std;
struct nod{
    int val;
    nod *leg;
} *first;
void push_b(int x){
    if(first == NULL){
        first = new nod;
        first->val = x;
        first->leg = NULL;
        return;
    }
    nod *r;
    r = first;
    while(r->leg != NULL){
        r = r->leg;
    }
    nod *p;
    p = new nod;
    r->leg = p;
    p->val = x;
    p->leg = NULL;
}
void push_f(int x){
    nod *p;
    p = new nod;
    p->val = x;
    p->leg = first;
    first = p;
}
void inser(int x, int pos){
    int nr = 1;
    nod *r, *p;
    r = first;
    while(r != NULL && nr < pos){
        ++nr;
        p = r;
        r = r->leg;
    }
    if(nr < pos)
        return;
    nod *q;
    q = new nod;
    q->val = x;
    q->leg = r;
    if(p != NULL)
        p->leg = q;
    else
        first = q;
}
void write(){
    nod *r;
    r = first;
    while(r != NULL){
        printf("%d ", r->val);
        r = r->leg;
    }
    printf("\n");
}
nod* search_val(int x){
    nod *r, *p;
    r = first;
    while(r != NULL && r->val != x){
        p = r;
        r = r->leg;
    }
    return p;
}
void delete_val(int x){
    nod *r;
    r = search_val(x);
    if(r == NULL){
        r = first;
        first = first->leg;
        delete r;
        return;
    }
    if(r->leg != NULL){
        nod *p;
        p = r->leg;
        r->leg = p->leg;
        delete p;
    }
}
nod* search_pos(int pos){
    nod *r, *p;
    p = NULL;
    r = first;
    int nr = 1;
    while(r != NULL && nr < pos){
        ++nr;
        p = r;
        r = r->leg;
    }
    return p;
}
void delete_pos(int pos){
    nod *r;
    r = search_pos(pos);
    if(r == NULL){
        r = first;
        first = first->leg;
        delete r;
        return;
    }
    if(r->leg != NULL){
        nod *p;
        p = r->leg;
        r->leg = p->leg;
        delete p;
    }
}
void del(){
    nod *p;
    while(first!= NULL){
        p = first->leg;
        delete first;
        first = p;
    }
}
int main(){
    push_f(2);
    write();
    push_f(1);
    write();
    inser(3, 3);
    write();
    delete_pos(2);
    write();
    delete_pos(1);
    write();
    return 0;
}
