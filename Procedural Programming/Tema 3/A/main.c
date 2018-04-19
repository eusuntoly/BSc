#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void f1(){
    //scrie doar numerele in fisierul date.out
    freopen("date.in", "r", stdin);
    freopen("date.out", "w", stdout);
    char s[260];
    while(gets(s) != NULL){
        int i = 0, ok = 0;
        while(s[i] != NULL){
            if(s[i] >= '0' && s[i] <= '9'){
                printf("%c", s[i]);
                ok = 1;
            }
            else
                if(ok){
                    ok = 0;
                    printf(" ");
                }
            ++i;
        }
        if(ok)
            printf(" ");
    }
}
int voc(char a[50], int n){
    char v[] = {"aeiou"};
    int i;
    if(!n)
        return 0;
    for(i = 0; i < n; ++i)
        if(strchr(v, a[i]) == NULL)
            return 0;
    return 1;
}
void f2(){
    //scrie in fisierul date.out toate cuvintele ce contin doar vocale
    freopen("date.in", "r", stdin);
    freopen("date.out", "w", stdout);
    char s[260];
    while(gets(s) != NULL){
        char c[50];
        int i = 0, j = 0;
        while(s[i] != NULL){
            if(s[i] != ' ')
                c[j++] = s[i];
            else{
                c[j] = NULL;
                if(voc(c, j))
                    printf("%s ", c);
                j = 0;
            }
            ++i;
        }
        if(j){
            c[j] = NULL;
            if(voc(c, j))
                printf("%s ", c);
        }
    }
}
void showMenu(){
    printf("Ce modificare doriti sa faceti?\n(1)Sa apara numai numerele.\n(2)Sa apara toate cuvintele care contin numai vocale.\nScrieti optiunea:\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            f1();
            break;
        case 2:
            f2();
            break;
        default:
            break;
    }
}
int main(){
    showMenu();
    return 0;
}
