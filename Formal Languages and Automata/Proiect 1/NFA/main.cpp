//NFA
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char L[100];
int T, n, I;
bool F[200];
char s[100];
vector<int> v[200][130];
bool NFA(int i, int stare){
    if(i == n){
        if(F[stare])
            return true;
        return false;
    }
    if(!v[stare][s[i]].size())
        return false;
    bool ok = false;
    for(int k = 0; k < v[stare][s[i]].size(); ++k)
        ok |= NFA(i + 1, v[stare][s[i]][k]);
   // for(int k = 0; k < v[stare]['+'].size(); ++k)
     //   ok |= NFA(i, v[stare]['+'][k]);
    return ok;
}
void solve(){
    scanf("%s", s);
    n = strlen(s);
    if(n == 1 && s[0] == '+'){
        if(F[I])
            printf("Cuvantul apartine limbajului.\n");
        else
            printf("Cuvantul nu apartine limbajului.\n");
        return;
    }
    if(NFA(0, I)){
        printf("Cuvantul apartine limbajului.\n");
        return;
    }
    printf("Cuvantul nu apartine limbajului.\n");
}
void show_menu(){
    printf("1. Introduceti cuvant.\n2. Exit.\n");
    int p;
    scanf("%d", &p);
    if(p == 1)
        solve(),
        show_menu();
    else
        return;
}
int main(){
    printf("Introduceti alfabetul, sub forma unui sir de caractere (vom considera 0 ca fiind caracterul nul), fara spatii:\n");
    scanf("%s", L);
    printf("Introduceti numarul de tranzitii:\n");
    scanf("%d", &T);
    printf("Introduceti tranzitiile, pe cate o linie de forma, starea1 starea2 litera:\n");
    for(int i = 1; i <= T; ++i){
        int x, y;
        char c;
        scanf("%d %d %c", &x, &y, &c);
        v[x][c].push_back(y);
    }
    printf("Introduceti starea initiala:\n");
    scanf("%d", &I);
    printf("Introduceti numarul starilor finale:\n");
    int y;
    scanf("%d", &y);
    printf("Introduceti lista starilor finale:\n");
    int x;
    for(int i = 1; i <= y; ++i){
        scanf("%d", &x);
        F[x] = true;
    }
    show_menu();
    return 0;
}
