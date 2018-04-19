#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct activity {
    int id, T, D;
} v[100];
struct cmp {
    bool operator()(const activity &x, const activity &y)const{
        if(x.D < y.D)
            return true;
        return false;
    }
};
int n;
int main() {
    f>>n;
    for(int i = 1; i <= n; ++i)
        f>>v[i].T>>v[i].D,
        v[i].id = i;
    sort(v + 1, v + n + 1, cmp());
    int time = 0;
    for(int i = 1; i <= n; ++i){
        g<<"activitatea "<<v[i].id<<": intervalul "<<time<<' '<<time + v[i].T<<" intarziere "<<(time + v[i].T - v[i].D > 0 ? time + v[i].T - v[i].D : 0)<<'\n';
        time += v[i].T;
    }
    return 0;
}
