#include <iostream>
#include <algorithm>
using namespace std;
class bst;
class nod{
    int key;
    nod *left, *right;
    friend class bst;
    friend bst operator--(bst &a);
    friend bst operator--(bst &a, int x);
    friend void leaves(bst &a);
    friend bool operator!=(bst a, bst b);
};
class bst{
    nod *top;
    void write(nod *node);
    void insert(nod *&node, int x);
    int inaltime(nod *node);
    void cmd(nod *&node, nod *&f);
    void sterg(nod *&node, int x);
    void frunze(nod *node);
    void sterge(nod *&node);
    void copy(nod *&node1, nod *node2);
    public:
        bst(){top = NULL;};
        bst(const bst &a){copy(top, a.top);};
        ~bst(){sterge(top);};
        void del(int x){sterg(top, x);};
        int height(){ return inaltime(top);};
        friend void leaves(bst &a);
        friend bst operator+(bst a, int x);
        friend ostream &operator<<(ostream &stream, bst a);
        friend bst operator>>(bst a, int x);
        friend bool operator!=(bst a, bst b);
        friend bst operator--(bst &a){--a.top->key; return a;};
        friend bst operator--(bst &a, int x){a.top->key--; return a;};
};
void leaves(bst &a){
    a.frunze(a.top);
}
void bst::copy(nod *&node1, nod *node2){
    if(node2){
        node1 = new nod;
        node1->key = node2->key;
        node1->left = NULL;
        node1->right = NULL;
        copy(node1->left, node2->left);
        copy(node1->right, node2->right);
    }
}
void bst::sterge(nod *&node){
    if(node){
        sterge(node->left);
        sterge(node->right);
        delete node;
        //node = NULL;
    }
}
void bst::write(nod *node){
    if(node){
        write(node->left);
        cout<<node->key<<" ";
        write(node->right);
    }
}
bool operator!=(bst a, bst b){
    return (a.top->key) != (b.top->key);
}
bst operator+(bst a, int x){a.insert(a.top, x); return a;}
ostream &operator<<(ostream &stream, bst a){a.write(a.top); return stream;}
bst operator>>(bst a, int x){a.insert(a.top, x); return a;}
void bst::insert(nod *&node, int x){
    if(node){
        if(node->key < x)
            insert(node->right, x);
        else
            insert(node->left, x);
    }
    else{
        node = new nod;
        node->key = x;
        node->left = NULL;
        node->right = NULL;
    }
}
int bst::inaltime(nod *node){
    if(node == NULL)
        return 0;
    int h = 0;
    h = 1 + inaltime(node->left);
    h = max(h, 1 + inaltime(node->left));
    return h;
}
void bst::cmd(nod *&node, nod *&f){
    nod *aux;
    if(f->right)
        cmd(node, f->right);
    else{
        node->key = f->key;
        aux = f;
        f = f->left;
        delete aux;
    }
}
void bst::sterg(nod *&node, int x){
    nod *aux;
    if(node){
        if(node->key == x){
            if(node->left == NULL && node->right == NULL){
                delete node;
                node = NULL;
            }
            else
                if(node->left == NULL){
                    aux = node->left;
                    delete node;
                    node = aux;
                }
                else
                    if(node->right == NULL){
                        aux = node->right;
                        delete node;
                        node = aux;
                    }
                    else
                        cmd(node, node->left);
        }
        else
            if(node->key < x)
                sterg(node->right, x);
            else
                sterg(node->left, x);
    }
}
void bst::frunze(nod *node){
    if(node){
        frunze(node->left);
        if(node->left == NULL && node->right == NULL)
            cout<<node->key<<" ";
        frunze(node->right);
    }
}
int main(){
    bst ob;
    ob = ob + 123;
    ob = ob + 12;
    cout<<ob;
    cout<<ob.height();
    cout<<'\n';
    //ob.leaves();
    cout<<'\n';
    ob.del(12);
    cout<<ob;
    return 0;
}
