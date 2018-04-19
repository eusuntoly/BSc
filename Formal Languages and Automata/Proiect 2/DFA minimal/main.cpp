//Input din fisier "date.in", de forma:
//Alfabetul folosit, ex: abc
//Starea initiala, ex: 0
//Numar stari finale, ex: 3
//Stari finale, ex: 2 3 4
//Numar tranzitii, ex: 16
//Tranzitiile pe cate o linie de forma: 0 1 a , 0 2 b etc
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool table[100][100], used[100];
int I[100][10], O[100][10], SI, N, T, L[100];
vector<int> SF;
vector<int> v[100];
bool isOK(int x){
    for(int i = 0; i < SF.size(); ++i)
        if(x == SF[i])
            return true;
    return false;
}
int main(){
    freopen("date.in", "r", stdin);
    char s[10];
    scanf("%s", s);
    scanf("%d %d", &SI, &N);
    for(int i = 0; i < N ;++i){
        int x;
        scanf("%d", &x);
        SF.push_back(x);
    }
    N = strlen(s);
    scanf("%d", &T);
    for(int i = 0; i < T; ++i){
        int a, b;
        char c;
        scanf("%d %d %c", &a, &b, &c);
        O[a][c - 'a'] = b;
        I[b][c - 'a'] = a;
    }
    bool ok = true;
    T /= N;
    for(int i = 0; i < T; ++i)
        for(int j = 0; j < i; ++j)
            if((isOK(i) && !isOK(j)) || (isOK(j) && !isOK(i)))
                    table[i][j] = true;
    while(ok){
        ok = false;
        for(int i = 0; i < T; ++i)
            for(int j = 0; j < i; ++j)
                if(!table[i][j])
                    for(int k = 0; k < N; ++k)
                        if(table[O[i][k]][O[j][k]] ||  table[O[j][k]][O[i][k]])
                            table[i][j] = true,
                            ok = true;
    }
    for(int i = 0; i < T; ++i)
        L[i] = i,
        v[i].push_back(i);
    for(int i = 0; i < T; ++i)
        for(int j = 0; j < i; ++j)
            if(!table[i][j]){
                L[j] = L[i];
                v[L[i]].push_back(j);
            }
    printf("Starea initiala: ");
    printf("%d", v[L[SI]][0]);
    for(int i = 1; i < v[L[SI]].size(); ++i)
        printf(",%d", v[L[SI]][i]);
    printf("\nStari finale: ");
    for(int i = 0; i < SF.size(); ++i)
        if(!used[L[SF[i]]]){
            used[L[SF[i]]] = true;
            printf("%d", v[L[SF[i]]][0]);
            for(int j = 1; j < v[L[SF[i]]].size(); ++j)
                printf(",%d", v[L[SF[i]]][j]);
            printf(" ");
        }
    printf("\n");
    for(int i = 0; i < T; ++i)
        if(L[i] == i)
            for(int j = 0; j < N; ++j){
                printf("%d", v[i][0]);
                for(int k = 1; k < v[i].size(); ++k)
                    printf(",%d", v[i][k]);
                printf(" -> ");
                printf("%d", v[L[O[i][j]]][0]);
                for(int k = 1; k < v[L[O[i][j]]].size(); ++k)
                    printf(",%d", v[L[O[i][j]]][k]);
                printf(" %c\n", j + 'a');
            }
    return 0;
}
