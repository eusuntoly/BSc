#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n, M[100], maxIndex[100];
struct nod{
    int start, finish, value, ind;
} v[100], a[100];
struct cmp1{
    bool operator()(const nod &a, const nod &b)const{
        if(a.finish < b.finish)
            return true;
        return false;
    }
};
struct cmp2{
    bool operator()(const nod &a, const nod &b)const{
        if(a.start < b.start)
            return true;
        return false;
    }
};
int solve(int j){
    if(j == 0)
        return 0;
    if(!M[j])
        M[j] = max(v[j].value + solve(maxIndex[j]), solve(j - 1));
    return M[j];
}
void write(int j){
    if(j == 0)
        return;
    if(v[j].value + M[maxIndex[j]] > M[j - 1]){
        write(maxIndex[j]);
        g<<v[j].start<<' '<<v[j].finish<<'\n';
        return;
    }
    write(j - 1);
}
int main(){
    f>>n;
    for(int i = 1; i <= n; ++i){
        f>>v[i].start>>v[i].finish>>v[i].value;
        v[i].ind = i;
        a[i] = v[i];
    }
    sort(v + 1, v + n + 1, cmp1());
    sort(a + 1, a + n + 1, cmp2());
    int t = 0, p[100];
    for(int i = 1; i <= n; ++i){
        while(v[t + 1].finish < a[i].start)
            ++t;
        p[a[i].ind] = t;
    }
    for(int i = 1; i <= n; ++i)
        maxIndex[i] = p[v[i].ind];
    g<<solve(n)<<'\n';
    write(n);
    return 0;
}
