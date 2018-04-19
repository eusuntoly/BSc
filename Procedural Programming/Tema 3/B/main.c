#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void f1(){
    //functia face glindirea cuvintelor ce contin 2 vocale
    FILE *in;
    in = fopen("intrare.txt", "rb+");
    char a[20], b[20], voc[] = {"AEIOUaeiou"}, c;
    int i = 0, j, k = 0, l = 0;
    while( (c = fgetc(in)) != EOF){
        if('A' <= c && c <= 'z'){
            a[i++] = c;
            for(j = 0; j <= 9; ++j)
                if(c == voc[j])
                    ++k;
        }
        else{
            if(k == 2){
                int p = 0;
                for(j = i - 1; j >= 0; --j)
                    b[p++]= a[j];
                b[p] = NULL;
                fseek(in, -p-1, SEEK_CUR);
                fwrite(b, p * sizeof(char), 1, in);
                fseek(in, l, SEEK_SET);
            }
            k = i = 0;
        }
        ++l;
    }
    fclose(in);
}
void f2(){
    //functia determina numarul de aparitii ale unui cuvant dat de la tastatura
    FILE *in;
    in = fopen("intrare.txt", "r");
    char a[20], b[20], c;
    int i = 0, nr = 0;
    scanf("%s", a);
    while(fscanf(in, "%c", &c) != EOF){
        if('A' <= c && c <= 'z')
            b[i++] = c;
        else
            if(i){
                b[i] = NULL;
                if(!strcmp(a, b))
                    ++nr;
                i = 0;
            }
    }
    printf("%d\n", nr);
    fclose(in);
}
void f3(){
    //functia determina cuvintele ce nu contin vocale, si le afiseaza pe ecran
    FILE *in;
    in = fopen("intrare.txt", "r");
    char a[20], voc[] = {"AEIOUaeiou"}, c;
    int i = 0, j, ok = 1;
    while(fscanf(in, "%c", &c) != EOF)
        if('A' <= c && c <= 'z'){
            a[i++] = c;
            for(j = 0; j <= 9; ++j)
                if(c == voc[j])
                    ok = 0;
        }
        else{
            a[i] = NULL;
            if(i && ok)
                printf("%s ", a);
            i = 0;
            ok = 1;
        }
    fclose(in);
}
void f4(){
    //functia transforma in fisier literele mari in litere mici si literele mici in litere mari, celelalte caractere raman neschimbate
    FILE *in;
    in = fopen("intrare.txt", "rb+");
    char a;
    int l = 0;
    while( (a = fgetc(in)) != EOF){
        printf("%c", a);
        if('A' <= a && a <= 'Z'){
            fseek(in, -1, SEEK_CUR);
            fputc(a + 'a' - 'A', in);
            fseek(in, l + 1, SEEK_SET);
        }
        else if('a' <= a && a <= 'z'){
            fseek(in, -1, SEEK_CUR);
            fputc(a - 'a' + 'A', in);
            fseek(in, l + 1, SEEK_SET);
        }
        ++l;
    }
    fclose(in);
}
void showMenu(){
    printf("Ce modificare doriti sa faceti?\n(1) Oglindirea cuvintelor ce contin 2 vocale.\n(2) Determinarea numarului de aparitii ale unui cuvant.\n(3) Determinarea cuvintelor ce nu contin vocale.\n(4) Transformarea literelor mici in litere mari, si invers.\nScrieti optiunea:\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            f1();
            break;
        case 2:
            f2();
            break;
        case 3:
            f3();
            break;
        case 4:
            f4();
            break;
        default:
            break;
    }
}
int main(){
    showMenu();
    return 0;
}
