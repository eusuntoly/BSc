//DFA
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char L[100];
int v[200][130], T, n, I;
bool F[200];
void solve(){
    char s[100];
    int stare = I;
    scanf("%s", s);
    if(strlen(s) == 1 && s[0] == '+'){
        printf("Cuvantul apartine limbajului.\n");
        return;
    }
    for(int i = 0; i < strlen(s); ++i)
        if(v[stare][s[i]] == -1){
            printf("Cuvantul nu apartine limbajului.\n");
            return;
        }
        else
            stare = v[stare][s[i]];
    if(F[stare]){
        printf("Cuvantul apartine limbajului.\n");
        return;
    }
    printf("Cuvantul nu apartine limbajului.\n");
}
void show_menu(){
    //system("cls");
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
    for(int i = 0; i <= 200; ++i)
        for(int j = 0; j <= 130; ++j)
            v[i][j] = -1;
    printf("Introduceti alfabetul, sub forma unui sir de caractere (vom considera 0 ca fiind caracterul nul), fara spatii:\n");
    scanf("%s", L);
    printf("Introduceti numarul de tranzitii:\n");
    scanf("%d", &T);
    printf("Introduceti tranzitiile, pe cate o linie de forma, starea1 starea2 litera:\n");
    for(int i = 1; i <= T; ++i){
        int x, y;
        char c;
        scanf("%d %d %c", &x, &y, &c);
        v[x][c] = y;
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
