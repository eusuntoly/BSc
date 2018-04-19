#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, size[100];
bool ok, lamda = 1;
char cuv[100], v[100][100][100];
void accept(char S, char *s1, char *s2, int k){
    for(int i = 0; i < size[S - 'A']; ++i){
        char s[100];
        memset(s, 0, sizeof(s));
        strncpy(s, s1, k);
        s[k + 1] = '\0';
        //printf("%s\n", s);
        if(v[S - 'A'][i][0] != '0' || cuv[0] == '0')
            strcat(s, v[S - 'A'][i]);
        strcat(s, s2);
        //printf("%s\n", s);
        int l = strlen(s) - 1;
        while(l > 0 && s[l] == '0') --l;
        s[l + 1] = '\0';
        if(!strcmp(cuv, s)){
            ok = true;
            break;
        }
        if(strlen(s) <= n * 2)
            for(int j = 0; j < strlen(s); ++j)
                if(s[j] >= 'A' && s[j] <= 'Z')
                    accept(s[j], s, s + j + 1, j);
    }
}
int main(){
    freopen("date.in", "r", stdin);
    char x, y[100], S;
    scanf("%s %c\n", cuv, &S);
    while(scanf("%c %s\n", &x, y) == 2){
        strcpy(v[x - 'A'][size[x - 'A']], y);
        ++size[x - 'A'];
    }
    n = strlen(cuv);
    for(int i = 0; i < size[S - 'A']; ++i){
        char s[100];
        memset(s, 0, sizeof(s));
        strcpy(s, v[S - 'A'][i]);
        if(!strcmp(cuv, s)){
            ok = true;
            break;
        }
        if(strlen(s) <= n * 2)
            for(int j = 0; j < strlen(s); ++j)
                if(s[j] >= 'A' && s[j] <= 'Z'){
                    //printf("%s\n", s+j+1);
                    accept(s[j], s, s + j + 1, j);
                }
    }
    if(ok)
        printf("Cuvant acceptat.\n");
    else
        printf("Cuvant respins.\n");
    return 0;
}
