//fisierul data.txt se ataseaza la proiect acolo fiind input-ul, cat si output-ul ca urmare a update-ului bazei
//s-ar putea facea fisiere pentru deparamente, limbaje, orase, dar am considerat ca ma extind prea mult
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N, n, ok, n_d, n_c, n_l, n_o;//n_d, n_c, n_l, n_o reprezinta numarul de departamente, calitati, etc.
char s[120];
struct angajati{
    char name[50], department[20], rank[9], language[15], city[15];
}A[100], x;
struct departamente{
    char name[20];
    int nr;
}D[50];
struct calitate{//facand referire la :Junior/Senior/Intern
    char name[6];
    int nr;
}C[3];
struct limbaje{
    char name[15];
    int nr;
}L[20];
struct oras{
    char name[15];
    int nr;
}O[50];
void (*tpf[15])(struct angajati *);
void parsare(struct angajati *a){
    int i = 0, j = 0;
    while(i < n && s[i] != ',' && s[i] != NULL && s[i] != '\n'){
        if(s[i] <= '9' && s[i] >= '0'){
            printf("%c", s[i]);
            printf("Nume gresit.\n");
            return;
        }
        (*a).name[j++] = s[i++];
    }
    (*a).name[j] = NULL;
    while(s[++i] == ' ' && s[i] != NULL && s[i] != '\n');
    j = 0;
    while(i < n && s[i] != ',' && s[i] != NULL && s[i] != '\n'){
        if(s[i] <= '9' && s[i] >= '0'){
            printf("Nume departament gresit.\n");
            return;
        }
        (*a).department[j++] = s[i++];
    }
    (*a).department[j] = NULL;
    while(s[++i] == ' ' && s[i] != NULL && s[i] != '\n');
    j = 0;
    while(i < n && s[i] != ',' && s[i] != NULL && s[i] != '\n'){
        if(s[i] <= '9' && s[i] >= '0'){
            printf("Calitate gresita.\n");
            return;
        }
        (*a).rank[j++] = s[i++];
    }
    (*a).rank[j] = NULL;
    while(s[++i] == ' ' && s[i] != NULL && s[i] != '\n');
    j = 0;
    while(i < n && s[i] != ',' && s[i] != NULL && s[i] != '\n')
        (*a).language[j++] = s[i++];
    (*a).language[j] = NULL;
    while(s[++i] == ' ' && s[i] != NULL && s[i] != '\n');
    j = 0;
    while(i < n && s[i] != ',' && s[i] != NULL && s[i] != '\n'){
        if(s[i] <= '9' && s[i] >= '0'){
            printf("Denumire oras gresita.\n");
            return;
        }
        (*a).city[j++] = s[i++];
    }
    (*a).city[j] = NULL;
    ok = 1;
}
void u_depart1(struct angajati *a){
    int i;
    for(i = 1; i <= n_d; ++i)
        if(!strcmp((*a).department, D[i].name)){
            ++D[i].nr;
            return;
        }
    strcpy(D[++n_d].name, (*a).department);
    D[n_d].nr = 1;
}
void u_rank1(struct angajati *a){
    int i;
    for(i = 1; i <= n_c; ++i)
        if(!strcmp((*a).rank, C[i].name)){
            ++C[i].nr;
            return;
        }
    strcpy(C[++n_c].name, (*a).rank);
    C[n_c].nr = 1;
}
void u_language1(struct angajati *a){
    int i;
    for(i = 1; i <= n_l; ++i)
        if(!strcmp((*a).language, L[i].name)){
            ++L[i].nr;
            return;
        }
    strcpy(L[++n_l].name, (*a).language);
    L[n_l].nr = 1;
}
void u_city1(struct angajati *a){
    int i;
    for(i = 1; i <= n_o; ++i)
        if(!strcmp((*a).city, O[i].name)){
            ++O[i].nr;
            return;
        }
    strcpy(O[++n_o].name, (*a).city);
    D[n_o].nr = 1;
}
void u_depart2(struct angajati *a){
    int i;
    for(i = 1; i <= n_d; ++i)
        if(!strcmp((*a).department, D[i].name)){
            --D[i].nr;
            return;
        }
}
void u_rank2(struct angajati *a){
    int i;
    for(i = 1; i <= n_c; ++i)
        if(!strcmp((*a).rank, C[i].name)){
            --C[i].nr;
            return;
        }
}
void u_language2(struct angajati *a){
    int i;
    for(i = 1; i <= n_l; ++i)
        if(!strcmp((*a).language, L[i].name)){
            --L[i].nr;
            return;
        }
}
void u_city2(struct angajati *a){
    int i;
    for(i = 1; i <= n_o; ++i)
        if(!strcmp((*a).city, O[i].name)){
            --O[i].nr;
            return;
        }
}
void add(struct angajati *a){
    ++N;
    A[N] = *a;
    tpf[3](a);
    tpf[4](a);
    tpf[5](a);
    tpf[6](a);
}
void del(struct angajati *a){
    int k = 0, i;
    for(i = 1; i <= N; ++i){
        printf("%s", A[i].name);
        if(!strcmp(A[i].name, (*a).name)){
            k = i;
            break;
        }
    }
    printf("%d", k);
    *a = A[k];
    tpf[7](a);
    tpf[8](a);
    tpf[9](a);
    tpf[10](a);
    A[k] = A[N];
    A[N] = A[N + 1];
    --N;
}
void read(){
    FILE *in;
    in = fopen("data.txt", "r");
    fscanf(in, "%d", &N);
    while(fgets(s, 150, in)){
        n = strlen(s);
        tpf[0](&x);
        if(ok)
            tpf[1](&x);
        ok = 0;
    }
    fclose(in);
}
void r(struct angajati *a){
    n = strlen(s);
    tpf[0](&x);
    if(ok)
        tpf[1](&x);
    ok = 0;
}
void w(struct angajati *a){
    n = strlen(s);
    tpf[0](&x);
    if(ok)
        tpf[2](&x);
    ok = 0;
}
void write(){
    FILE *out;
    out = fopen("data.txt", "w+");
    int i;
    for(i = 1; i <= N; ++i)
        fprintf(out, "%s, %s, %s, %s, %s\n", A[i].name, A[i].department, A[i].rank, A[i].language, A[i].city);
}
int cmp(const void *a, const void *b){
    struct angajati *orderA = (struct angajati *)a;
    struct angajati *orderB = (struct angajati *)b;
    return strcmp(orderA->name, orderB->name);
}
void showMenu(){
    enum{ADAUGA = 11, STERGE = 12, EXIT = 0};
    system("cls"); //e optional, si putin instabil din cate stiu
    printf("Ce operatiune doriti sa faceti?\n(1)ADAUGA - De forma: Nume angajat, Departament, Calitate(Senior/Junior/Intern), Limbaj preferat, Orasul.\n(2)STERGE - De forma: Nume angajat.\n(3)EXIT\nScrieti optiunea:\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            fgets(s, 150, stdin);
            fgets(s, 150, stdin);
            tpf[ADAUGA](&x);
            showMenu();
        case 2:
            fgets(s, 150, stdin);
            fgets(s, 150, stdin);//am pastrat varianta cu cate 2 fgets, pentru a nu mai trebui sa introduc de 2 ori codul de iesire
            tpf[STERGE](&x);
            showMenu();
        case 3:
            break;
        default:
            showMenu();
    }
}
int main(){
    tpf[0] = parsare;
    tpf[1] = add;
    tpf[2] = del;
    tpf[3] = u_depart1;
    tpf[4] = u_rank1;
    tpf[5] = u_language1;
    tpf[6] = u_city1;
    tpf[7] = u_depart2;
    tpf[8] = u_rank2;
    tpf[9] = u_language2;
    tpf[10] = u_city2;
    tpf[11] = r;
    tpf[12] = w;
    read();
    qsort(A, N + 1, sizeof(struct angajati), cmp);
    showMenu();
    write();//rescrie fisierul de bazei de date
    return 0;
}

