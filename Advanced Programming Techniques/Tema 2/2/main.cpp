#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct node{
    int data;
    node *left;
    node *right;
} *root;
int inIndex[100], inOrder[100], postOrder[100];
bool used[100];
node* buildTree(int inOrder[], int postOrder[], int n, int offset){
    if(!n)
        return nullptr;
    int rootData = postOrder[n - 1];
    if(used[rootData]){
        g<<"nu\n";
        exit(1);
    }
    used[rootData] = true;
    int rootIndex = inIndex[rootData] - offset;
    node *root = new node;
    root->data = rootData;
    cout<<rootData<<' '<<rootIndex<<' '<<n<<' '<<offset<< '\n';
    root->left = buildTree(inOrder, postOrder, rootIndex, offset);
    root->right = buildTree(inOrder + rootIndex + 1, postOrder + rootIndex, n - rootIndex - 1, offset + rootIndex + 1);
    return root;
}
void preOrder(node* nod){
    if(nod == NULL)
        return;
    g<<nod->data<<' ';
    preOrder(nod->left);
    preOrder(nod->right);
}
int main(){
    int n;
    f>>n;
    for(int i = 0; i < n; ++i)
        f>>postOrder[i];
    for(int i = 0; i < n; ++i){
        f>>inOrder[i];
        inIndex[inOrder[i]] = i;
    }
    root = buildTree(inOrder, postOrder, n, 0);
    preOrder(root);
    return 0;
}
